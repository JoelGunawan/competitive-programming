#!/bin/bash

NAME=backup

/usr/bin/g++ -o $NAME grader.cpp server.cpp client.cpp -O2 -lm -std=c++17