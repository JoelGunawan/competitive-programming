This problem is an interactive problem.

Your program is expected to communicate with an interactor program
through the standard input/output. Your program must give a correct
response to the interactor in each step of the communication.
The C++ source code of an interactor program is provided as
interactor.cc and validate_domjudge.h.

Usage of the interactor (let interactor.out be the executable file name):

  $ ./interactor.out <input data> <answer file> <feedback dir>

<input data> is the input file (*.in file in this directory).

<answer file> is the corresponding answer file to the input file (*.ans
  in this directory).

<feedback dir> is a directory that the interactor uses.

The interactor's standard input/output must be connected to your
program's standard output/input, respectively.
If your program gives a valid output to the interactor in each step of
the communication and reaches a correct answer, interactor exits with
exit code 42, which is stored in $? shell variable. Otherwise, it exits
with another exit code.

Example:

If your program is "solve" and execute it with input 01.in,

$ mkdir feedback
$ mkfifo fifo
$ ./main < fifo | ./interactor.out 01.in 01.ans feedback > fifo
(no command should be executed here)
$ echo $?

Being displayed 42 by the command "echo $?", your program answered
correctly for input 01.in. When the program output is incorrect,
43 is displayed instead.

For your convenience, a command-line tool for testing interactions is
attached as "run.bash". To run the testing tool, compile interactor.cc
and validate_domjudge.h as "interactor.out".  The usage of the tool
and the format of its input file will be displayed by executing run.bash
with no arguments.
