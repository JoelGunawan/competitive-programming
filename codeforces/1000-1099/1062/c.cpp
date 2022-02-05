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
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll addmod(ll a, ll b) {
    return (((a + b) % mod) + mod) % mod;
}
ll mulmod(ll a, ll b) {
    return (a * b) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    ll pref[n + 1];
    memset(pref, 0, sizeof(pref));
    for(int i = 1; i <= n; ++i) {
        char x;
        cin >> x;
        x -= '0';
        pref[i] = pref[i - 1] + x;
    }
    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        int one_cnt = pref[r] - pref[l - 1], zero_cnt = r - l + 1 - one_cnt;
        cout << addmod(powmod(2, one_cnt) - 1, mulmod(powmod(2, one_cnt) - 1, powmod(2, zero_cnt) - 1)) << endl;
    }
    return 0;
}