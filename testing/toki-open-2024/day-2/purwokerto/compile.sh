#!/bin/bash

problem="purwokerto"
grader_name="grader"

g++-13 -std=c++17 -o "${problem}" "${grader_name}.cpp" "${problem}.cpp" -O2 -lm
