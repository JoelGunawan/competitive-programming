set NAME=question

g++ -o %NAME% grader.cpp answerer.cpp shouter.cpp -O2 -lm -std=c++11
