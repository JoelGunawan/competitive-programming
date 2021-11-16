#include <bits/stdc++.h>
using namespace std;
int mod = 10;
int powmod(int a, int b) {
    if(b == 0)
        return a;
    else {
        int tmp = powmod(a, b / 2); tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main() {
    int a[(int)1e6 + 1]; a[0] = 0;
    for(int i = 1; i <= 1e6; ++i) {
        a[i] = (a[i - 1] + powmod(i % mod, i)) % mod;
    }
    int t, n;
    cin >> t;
    while(t--)
        cin >> n, cout << a[n] << endl;
    return 0;
}