#!/bin/bash

problem="secret"
grader_name="grader"

g++-13 -std=c++17 -o "${problem}" "${grader_name}.cpp" "${problem}.cpp" -O2 -lm
