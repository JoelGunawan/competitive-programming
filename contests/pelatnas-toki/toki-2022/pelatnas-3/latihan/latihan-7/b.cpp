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
void solve() {
    string s;
    cin >> s;
    // find shortest possible
    // dari ujung luar
    ll curL = 0, curR = 0, tmp = 1;
    int cnt = 0;
    for(int i = 0; i < s.size() / 2; ++i) {
        // cari apakah hashing curR sama dengan hashing curL
        curL = curL * 26 + s[i];
        curR = curR + tmp * s[s.size() - i - 1];
        curL %= mod;
        curR %= mod;
        tmp *= 26;
        tmp %= mod;
        if(curL == curR) {
            cnt += 2, tmp = 1, curL = 0, curR = 0;
        }
    }
    if(tmp == 1 && s.size() % 2 == 0) {

    }
    else {
        ++cnt;
    }
    cout << cnt << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--)
        solve();
    return 0;
}