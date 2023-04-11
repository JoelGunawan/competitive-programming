#!/bin/bash

problem=shoes

g++-12 -o "${problem}" "grader.cpp" "${problem}.cpp"
