#!/bin/bash

problem=conveyor
grader_name=grader

g++ -std=c++17 -O2 -Wall -pipe -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"
