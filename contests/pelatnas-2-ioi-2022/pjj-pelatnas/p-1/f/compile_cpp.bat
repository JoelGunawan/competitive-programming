set problem=art
set grader_name=grader

g++ -o %problem% %grader_name%.cpp %problem%.cpp -std=gnu++11 -O2 -Wall -pipe -static
