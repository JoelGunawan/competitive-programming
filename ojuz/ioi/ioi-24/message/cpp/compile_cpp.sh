#!/bin/bash

problem="message"
grader_name="grader"

g++-15 -std=gnu++17 -Wall -O2 -g -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"
