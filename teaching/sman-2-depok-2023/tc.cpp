#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << n << endl;
    mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
    for(int i = 0; i < n; ++i) {
        cout << rng() % (int)n + 1 << " ";
    }
    cout << endl;
}