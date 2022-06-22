SETLOCAL 
set NAME=friends

g++ -o %NAME% grader.cpp %NAME%.cpp -O2 -lm -std=c++17
ENDLOCAL 