#!/bin/bash

problem=supertrees
grader_name=grader

g++-12 -O2 -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"
