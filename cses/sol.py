import sys
from collections import defaultdict

def main() -> None:
    data = list(map(int, sys.stdin.buffer.read().split()))
    if not data:
        return
    it = iter(data)
    n = next(it)
    x = next(it)

    # 1-indexed to match the C++ code's indices
    a = [0] + [next(it) for _ in range(n)]

    suf = defaultdict(int)

    # Precompute counts of pair sums for all (j < i)
    for i in range(1, n + 1):
        ai = a[i]
        for j in range(1, i):
            suf[ai + a[j]] += 1

    for i in range(1, n + 1):
        ai = a[i]
        for j in range(1, i):
            need = x - ai - a[j]
            if suf.get(need, 0) > 0:
                # Find actual k,l to output indices (same as C++ brute force)
                for k in range(i + 1, n + 1):
                    s3 = ai + a[j] + a[k]
                    for l in range(k + 1, n + 1):
                        if s3 + a[l] == x:
                            sys.stdout.write(f"{i} {j} {k} {l}\n")
                            return

        # Remove pair sums that involve i as the "left side" for future iterations
        for j in range(i + 1, n + 1):
            key = ai + a[j]
            suf[key] -= 1
            if suf[key] == 0:
                del suf[key]

    sys.stdout.write("IMPOSSIBLE\n")

if __name__ == "__main__":
    main()