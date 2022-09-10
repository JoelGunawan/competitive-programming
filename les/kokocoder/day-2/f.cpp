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
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
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
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i] = mp(x, y);
        ll tmp = gcd(abs(x), abs(y));
        //cout << a[i].fi << " " << a[i].se << " " << tmp << endl;
        if(tmp != 0)
            a[i].fi /= tmp, a[i].se /= tmp;
        //cout << a[i].fi << " " << a[i].se << endl;
        if(a[i].fi < 0 && a[i].se < 0)
            a[i].fi *= -1, a[i].se *= -1;
        if(a[i].se < 0 && a[i].fi > 0)
            a[i].fi *= -1, a[i].se *= -1;
    }
    // a[i] == 0 b[i] == 0
    // a[i] == 0
    // b[i] == 0
    // sisanya
    map<pair<int, int>, int> b;
    for(int i = 0; i < n; ++i) {
        b[a[i]]++;
    }
    ll res1 = 1;
    vector<pair<int, int>> nonzero;
    for(auto i : b) {
        if(i.first.first != 0 && i.first.second != 0)  
            nonzero.pb(i.first);
    }
    map<pair<int, int>, bool> vis;
    for(auto i : nonzero) {
        //cout << i.fi << " " << i.se << endl;
        if(!vis[i]) {
            vis[i] = 1;
            pair<int, int> inv = i;
            inv = {-inv.se, inv.fi};
            if(inv.fi < 0 && inv.se < 0)
                inv.fi *= -1, inv.se *= -1;
            if(inv.fi > 0 && inv.se < 0) {
                inv.fi *= -1, inv.se *= -1;
            }
            vis[inv] = 1;
            // 2^(cnti) + 2^(cntj) - 1
            res1 *= (powmod(2, b[i]) + powmod(2, b[inv]) - 1) % mod;
            res1 %= mod;
        }
    }
    // hasil nonzero
    // A[i] == 0 sendiri
    // B[i] == 0 sendiri
    // A[i] == 0 B[i] == 0 -> tambah di akhir
    int azero = 0, bzero = 0, allzero = 0;
    for(auto i : b) {
        if(i.fi.fi == 0 && i.fi.se == 0)
            ++allzero;
        if(i.fi.fi == 0 && i.fi.se != 0)
            ++azero;
        if(i.fi.fi != 0 && i.fi.se == 0)
            ++bzero;
    }
    ll res = res1 - 1 + ((powmod(2, azero) - 1) * res1) % mod + ((powmod(2, bzero) - 1) * res1) % mod + allzero;
    res %= mod;
    cout << res << endl;
    return 0;
}