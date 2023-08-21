set PROBLEM=knapsack
set GRADER=grader

g++ -std=c++17 -O2 -Wall -pipe -o %PROBLEM% %grader%.cpp %PROBLEM%.cpp
