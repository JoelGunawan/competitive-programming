#!/bin/bash

problem="coreputer"
grader_name="grader"

g++-12 -std=gnu++17 -O2 -Wall -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"
