set problem=reverse
set grader_name=grader

g++ -o %problem% %grader_name%.cpp %problem%.cpp -std=gnu++17 -O2 -Wall -pipe -static