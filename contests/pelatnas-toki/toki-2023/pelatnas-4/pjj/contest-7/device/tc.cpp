#include <bits/stdc++.h>
using namespace std;
int main() {
    mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());
    for(int i = 0; i < 5; ++i) {
        int sz = rng() % 41;
        cout << 150 << " " << rng() % (int)(1e18 + 1) << " " << sz << endl;
        set<int> s;
        while(s.size() < sz)
            s.insert(rng() % 150);
        for(auto i : s)
            cout << i << " ";
        cout << endl;
    }
}