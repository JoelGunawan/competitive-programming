#include <bits/stdc++.h>
using namespace std;
int main() {
    // buat test case random
    mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
    // buat array random
    int n = rng() % 20; // 0...99
    n += 1;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        a[i] = rng() % 100000;
        a[i]++;
    }
    cout << n << endl;
    for(int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << endl;
}