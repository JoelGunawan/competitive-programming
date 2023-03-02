SETLOCAL 
set NAME=latihan_memasak

g++ -o %NAME% grader.cpp %NAME%.cpp -O2 -lm -std=c++11
ENDLOCAL 