@echo off

set NAME=panggung

set CPP=g++
set CPPFLAGS=-Wall -O2 -std=c++17

%CPP% %CPPFLAGS% -o %NAME% grader.cpp %NAME%.cpp

if %ERRORLEVEL% == 0 (
    echo [32mCompilation successful![0m
) else (
    echo [31mCompilation failed![0m
)

pause