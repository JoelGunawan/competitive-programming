#!/bin/bash

problem="country"
grader_name="grader"

g++ -std=c++20 -o "${problem}" "${grader_name}.cpp" "${problem}.cpp" -O2 -lm
