SETLOCAL 
set NAME=simulasi_pertarungan

g++ -o %NAME% grader.cpp %NAME%.cpp -O2 -lm -std=c++11
ENDLOCAL 