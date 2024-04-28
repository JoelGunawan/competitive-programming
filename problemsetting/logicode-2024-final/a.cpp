// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
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
ll f(int n) {
    if(n == 1)
        return 0;
    return ((powmod(2, n - 1) * (n - 1)) + f(n - 1)) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    ll res = f(n);
    if(res < 0)
        res += mod;
    cout << res << endl;
    return 0;
}