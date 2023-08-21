#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    if(b == 0)  
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main() {
    // init -> 3 bebas, 1 ikut
    // rest -> 
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    // n + m - 1
    cout << powmod(k + 1, n + m - 1) << endl;
}