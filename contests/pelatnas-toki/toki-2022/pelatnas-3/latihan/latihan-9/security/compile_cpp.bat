SETLOCAL 
set NAME=security

g++ -o %NAME% grader.cpp hacker.cpp spy.cpp -O2 -lm -std=c++17
ENDLOCAL