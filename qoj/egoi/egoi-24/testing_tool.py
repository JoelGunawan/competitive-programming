#!/usr/bin/env python3

"""
Example usage:

First create an input file, like "sample1.in" with the following contents:
6
1 2 0 4 3 5
1 1 0 0 1 0

For python programs, say "solution.py" (normally run as "pypy3 solution.py"):

    python3 testing_tool.py pypy3 solution.py < sample1.in

For C++ programs, first compile it
(e.g. with "g++ -g -O2 -std=gnu++20 -static  solution.cpp -o solution.out")
and then run

    python3 testing_tool.py ./solution.out < sample1.in

"""

import sys
import os
import signal
from collections import Counter
from typing import List
from io import BufferedReader, BufferedWriter

F_SETPIPE_SZ = 1031

MAX_ROUNDS = 60

PRINT_FULL_STATE_BELOW = 100


def error(msg: str) -> None:
    print("ERROR:", msg, file=sys.stderr)
    sys.exit(1)

def parse_int(s: str, what: str, lo: int, hi: int) -> int:
    try:
        ret = int(s)
    except Exception:
        error(f"Failed to parse {what} as integer: {s}")
    if not (lo <= ret <= hi):
        error(f"{what} out of bounds: {ret} not in [{lo}, {hi}]")
    return ret

def list_to_str(li: List[int], delim: str) -> str:
    lim = PRINT_FULL_STATE_BELOW
    sli = [str(x) for x in li]
    if len(li) > lim:
        sli = sli[:lim//2] + ["..."] + sli[len(li) - lim//2:]
    return delim.join(sli)

def wait_for_child(pid: int) -> None:
    pid, status = os.waitpid(pid, 0)
    if os.WIFSIGNALED(status):
        sig = os.WTERMSIG(status)
        error(f"Program terminated with signal {sig} ({signal.Signals(sig).name})")
    ex = os.WEXITSTATUS(status)
    if ex != 0:
        error(f"Program terminated with exit code {ex}")

def read_line(pid: int, file: BufferedReader, what: str) -> str:
    line = file.readline()
    if not line:
        wait_for_child(pid)
        error(f"Failed to read {what}: no more output")
    return line.decode("latin1").rstrip("\r\n")

def write_line(file: BufferedWriter, line: str) -> None:
    try:
        file.write((line + "\n").encode("ascii"))
        file.flush()
    except BrokenPipeError:
        pass

def run_submission(submission: List[str], cur_round: int, perm: List[int], bits: List[int], silent: bool) -> List[int]:
    n = len(perm)

    sys.stdout.flush()
    sys.stderr.flush()

    c2p_read, c2p_write = os.pipe()
    p2c_read, p2c_write = os.pipe()
    pid = os.fork()

    if pid == 0:
        os.close(p2c_write)
        os.close(c2p_read)

        os.dup2(p2c_read, 0)
        os.dup2(c2p_write, 1)

        try:
            os.execvp(submission[0], submission)
        except Exception as e:
            error(f"Failed to execute program: {e}")
        assert False, "unreachable"
    else:
        os.close(c2p_write)
        os.close(p2c_read)

        ret = []
        with os.fdopen(p2c_write, "wb") as fout:
            with os.fdopen(c2p_read, "rb") as fin:
                write_line(fout, f"{cur_round} {n}")
                write_line(fout, " ".join(map(str, perm)))
                if cur_round == 0:
                    line = read_line(pid, fin, "number of rounds")
                    ret.append(parse_int(line, "number of rounds", 0, MAX_ROUNDS))
                else:
                    for bit in bits:
                        write_line(fout, str(bit))
                        line = read_line(pid, fin, "bit")
                        new_bit = parse_int(line, "bit", 0, 1)
                        if not silent:
                            print(f"[*] {bit} => {new_bit}")
                        ret.append(new_bit)

                # Wait for program to terminate, and read all its output
                remainder = fin.read().decode("latin1")
                if remainder.strip():
                    error(f"Unexpected trailing output: {remainder}")
                try:
                    fin.close()
                except BrokenPipeError:
                    pass
                try:
                    fout.close()
                except BrokenPipeError:
                    pass

        wait_for_child(pid)
        return ret

def main() -> None:
    silent = False
    args = sys.argv[1:]
    if args and args[0] == "--silent":
        args = args[1:]
        silent = True
    if not args:
        print("Usage:", sys.argv[0], "[--silent] program... <input.txt")
        sys.exit(0)

    n = parse_int(input(), "N", 1, 10**9)
    perm_toks = input().split()
    if len(perm_toks) != n:
        error(f"Second line must have {n} values, but got {len(perm_toks)}")
    perm = [parse_int(x, "permutation index", 0, n-1) for x in perm_toks]

    what, occ = Counter(perm).most_common(1)[0]
    if occ != 1:
        error(f"Second line must be a permutation of 0, ..., N-1, but {what} occurs {occ} times")

    bits_toks = input().split()
    if len(bits_toks) != n:
        error(f"Third line must have {n} values, but got {len(bits_toks)}")
    bits = [parse_int(x, "input bit", 0, 1) for x in bits_toks]

    target_bits = [bits[perm[i]] for i in range(n)]

    print(f"[*] Running round 0 (N = {n}, goal permutation = {list_to_str(perm, ', ')})")
    print(f"[*] b = {list_to_str(bits, '')}")

    num_rounds = run_submission(args, 0, perm, [], silent)[0]

    print(f"[*] Got x = {num_rounds}")

    for it in range(num_rounds):
        print(f"[*] Running round {it+1}")
        if it % 2:
            bits.reverse()
        bits = run_submission(args, it + 1, perm, bits, silent)
        if it % 2:
            bits.reverse()
        print(f"[*] b = {list_to_str(bits, '')}")

    if bits == target_bits:
        print(f"[*] OK: x = {num_rounds}")
    else:
        print(f"[*] Wrong Answer: expected b =\n        {list_to_str(target_bits, '')}")
        if list_to_str(bits, "") == list_to_str(target_bits, ""):
            # Just in case cropping hid the difference
            for i in range(n):
                if bits[i] != target_bits[i]:
                    print(f"[*] (diff at position i={i}, zero-indexed)")
                    break
            else:
                assert False

if __name__ == "__main__":
    main()