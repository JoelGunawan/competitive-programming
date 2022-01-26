#!/bin/bash

problem=art
grader_name=grader

g++ -std=gnu++11 -O2 -Wall -pipe -static -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"
