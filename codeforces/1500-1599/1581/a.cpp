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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll fact[(int)2e5 + 1];
    fact[0] = 1;
    for(int i = 1; i <= 2e5; ++i)
        fact[i] = (fact[i - 1] * i) % mod;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << (fact[2 * n] * powmod(2, mod - 2)) % mod << endl;
    }
    return 0;
}