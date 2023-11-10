/*
SAMPLE GRADER for task LIGHT

USAGE:
place together with your solution and light.h in the same directory, then:
g++ <flags> sample_grader.cpp <solution_file>
e.g.:
g++ -std=c++17 sample_grader.cpp light.cpp

INPUT/OUTPUT:
The sample grader first expects on standard input the integer Q. It then writes
to standard output a protocol of all calls to the three functions prepare, join,
and leave.

In the beginning, the grader calls prepare(). Then it simulates the Q acts. For
each act a, it expects on standard input either an integer p_a > 0, meaning that
p_a performers join the line, or an integer q_a < 0, meaning that p_a = -q_a
performers leave the line; it will then call join(p_a) or leave(p_a),
respectively.

Upon termination, it writes your verdict to standard output.
*/
#include "light.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

namespace {

double maxQuotient = 0.0;
ll N = 1;
size_t maxFires = 1;
vector<ll> fires = {1};
constexpr int MAX_NUM_FIRES = 150;

[[noreturn]] void die(string msg)
{
    cout << msg << endl;
    exit(0);
}

void check(ll p, pair<ll, vector<ll>> res) {
    ll t = res.first;
    vector<ll> newFires = res.second;
    maxQuotient = max(maxQuotient, static_cast<double>(t)/abs(static_cast<double>(p)));
    maxFires = max(maxFires, newFires.size());

    cout << (p < 0? "leave" : "join") << "(" << llabs(p) << ") returned " << t << ", {";
    for(size_t i = 0; i < newFires.size(); i++) {
        cout << newFires[i];
        if(i + 1 < newFires.size()) cout << ", ";
    }
    cout << "}" << endl;

    if(t < 0 || t > 5 * static_cast<__int128_t>(llabs(p))) die("Invalid return value");
    for(size_t i = 0; i + 1 < newFires.size(); i++) {
        if(newFires[i] >= newFires[i + 1]) die("Invalid return value");
    }
    if(!newFires.empty() && (newFires[0] <= 0 || newFires.back() > N)) die("Invalid return value");
    if(newFires.size() > MAX_NUM_FIRES) die("Too many burning torches");
    if(newFires.empty() || newFires.back() < N) die("Rightmost torch not on fire");


    size_t i = 0;
    for (ll x : newFires) {
        for (;; ++i) {
            if (i >= fires.size() || fires[i] > x) die("Not all announced torches have been lit");
            if (fires[i] + t >= x) break;
        }
    }
    fires = newFires;
}

};

int main() {
    int Q;
    if (!(cin >> Q)) die("Invalid input");

    cout << "prepare()" << endl;
    prepare();

    for (int i = 0; i < Q; i++) {
        ll p;
        if (!(cin >> p) || p == 0) die("Invalid input");
        N += p;
        if (N <= 0) die("The stage is empty");
        if (p > 0)  check(p, join(p));
        if (p < 0)  check(p, leave(-p));
    }

    cout << "Correct: ratio at most " << maxQuotient << ", at most " << maxFires << " burning torches" << endl;
    return 0;
}
