// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,sse4,avx2,mmx,tune=native")
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
ll cross_product(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    b.fi -= a.fi;
    c.fi -= a.fi;
    b.se -= a.se;
    c.se -= a.se;
    return b.fi * c.se - c.fi * b.se;
}
int mod = 998244353;
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
    // kalo n kecil bisa coba tiap subset terus cari convex hull dr mask sekarang
    int n;
    cin >> n;
    if(n > 14) {
        cout << 0 << endl;
        return 0;
    }
    pair<ll, ll> b[n];
    for(int i = 0; i < n; ++i)
        cin >> b[i].fi >> b[i].se;
    ll res = 0;
    for(int i = 0; i < (1 << n); ++i) {
        vector<pair<ll, ll>> a;
        for(int j = 0; j < n; ++j) {
            if((1 << j) & i)
                a.pb(b[j]);
        }
        if(a.size() < 3) {
            continue;
        }
        vector<pair<ll, ll>> s;
        s.pb(a[0]);
        s.pb(a[1]);
        for(int i = 2; i < a.size(); ++i) {
            // consider everything in a
            while(s.size() > 1 && cross_product(s[s.size() - 2], s[s.size() - 1], a[i]) < 0)
                s.pop_back();
            s.pb(a[i]);
        }
        set<pair<ll, ll>> ans;
        for(auto i : s)
            ans.ins(i);
        s.clear();
        s.pb(a[a.size() - 1]);
        s.pb(a[a.size() - 2]);
        for(int i = a.size() - 3; i >= 0; --i) {
            while(s.size() > 1 && cross_product(s[s.size() - 2], s[s.size() - 1], a[i]) < 0)
                s.pop_back();
            s.pb(a[i]);
        }
        for(auto i : s)
            ans.ins(i);
        res += powmod(2, a.size() - ans.size());
    }
    res %= mod;
    cout << res << endl;
    return 0;
}