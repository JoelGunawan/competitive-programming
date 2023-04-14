#!/bin/bash

problem=dna
grader_name=grader

g++-12 -std=gnu++17 -O2 -Wall -pipe -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"
