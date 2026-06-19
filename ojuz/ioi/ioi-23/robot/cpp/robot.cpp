#include "robot.h"
#include <bits/stdc++.h>
using namespace std;

void program_pulibot() {
    set_instruction({0, -2, -1, 0, -2}, 1, 'E');
    set_instruction({0, 1, -1, 0, -2}, 1, 'E');
    set_instruction({0, 1, 0, -2, -2}, 1, 'S');
    set_instruction({0, -1, -2, -2, 1}, 1, 'T');
}
