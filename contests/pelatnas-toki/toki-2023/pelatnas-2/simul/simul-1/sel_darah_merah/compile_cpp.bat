SETLOCAL 
set NAME=sel_darah_merah

g++ -o %NAME% grader.cpp %NAME%.cpp -O2 -lm -std=c++11
ENDLOCAL 