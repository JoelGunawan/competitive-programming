#!/bin/bash

problem=maze
grader_name=grader

g++-12 -std=c++17 -O2 -Wall -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"
