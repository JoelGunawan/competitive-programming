#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    // n kinds m boxes
    // one of the boxes has to be filled at least
    // tiap subset kecuali 1
    // (2^m-1)^n
    cout << powmod(powmod(2, m) - 1, n) << endl;
}