// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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
ll fact[105], inv[105];
ll combinmod(ll a, ll b) {
    return (fact[a] * ((inv[b] * inv[a - b]) % mod)) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    // cari x itu berapa
    // pola: 
    // 1 2 4 8 ...
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= n; ++i)
        fact[i] = (fact[i - 1] * i) % mod, inv[i] = powmod(fact[i], mod - 2);
    //for(int i = 1; i <= 12; ++i)
    //    cout << fact[i] << " " << inv[i] << endl;
    int tmp = 1, cnt = 0;
    while(tmp < x) {
        tmp *= 2;
        ++cnt;
    }
    if(tmp != x || cnt >= n) {
        cout << -1 << endl;
        return 0;
    }
    //cout << n - 1 << " " << cnt << endl;
    cout << combinmod(n - 1, cnt) << endl;
    return 0;
}