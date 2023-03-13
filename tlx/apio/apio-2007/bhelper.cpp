#include <bits/stdc++.h>
using namespace std;
int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int x = rng() % 15 + 1, y = rng() % x / 2 + 1;
    int tmp = 0;
    cout << x << " " << y << endl;
    for(int i = 0; i < x; ++i)
        tmp += rng() % 1000, cout << tmp << " ";
    cout << endl;
}