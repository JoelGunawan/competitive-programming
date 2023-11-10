#!/bin/bash

problem=box
grader_name=grader

g++-12 -O2 -Wall -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"
