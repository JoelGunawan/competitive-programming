#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long x[n], y[n];
    for(int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    long long res = 0;
    for(int i = 0; i < n; ++i) {
        res += x[i] * y[(i + 1) % n] - x[(i + 1) % n] * y[i];
    }
    res = abs(res);
    // res /= 2 -> tidak perlu karena diminta 2 kali luas
    cout << res << endl;
}