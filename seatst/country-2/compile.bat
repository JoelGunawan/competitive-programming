@echo off
SETLOCAL
set problem=country
set grader_name=grader

g++ -std=c++20 -o "%problem%" "%grader_name%.cpp" "%problem%.cpp" -O2 -lm
ENDLOCAL
