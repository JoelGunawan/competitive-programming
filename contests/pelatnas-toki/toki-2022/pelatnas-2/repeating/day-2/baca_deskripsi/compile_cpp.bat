@echo off
SETLOCAL
set NAME=baca_deskripsi
g++ -o %NAME% grader.cpp %NAME%.cpp -O2 -lm -std=c++11
ENDLOCAL