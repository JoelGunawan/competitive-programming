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
int mod = 998244353;
ll powmod(ll a, ll b) {
    if(b == 0) {
        return 1;
    }
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
    int a[n + 1], ori[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i], ori[i] = a[i];
    // max of multiple
    ll mx[n + 1];
    vector<pair<int, int>> v;
    vector<int> o;
    for(int i = 1; i <= n; ++i)
        v.pb(mp(a[i], i));
    sort(v.begin(), v.end());
    for(int i = 0; i < n; ++i)
        a[v[i].se] = i, o.pb(v[i].se);
    vector<int> b;
    for(int i = 1; i <= n; ++i) {
        mx[i] = 0;
        for(int j = i; j <= n; j += i)
            mx[i] = max(mx[i], (ll)a[j]);
        b.pb(mx[i]);
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    int cnt = 0;
    ll res[n + 1];
    for(auto x : o) {
        // proses x dulu, cek ada berapa point cnt yg <= a[x] maxnya
        int cur_cnt = 0;
        while(b.size() && b.back() <= a[x]) {
            if(b.back() == a[x])
                ++cur_cnt;
            ++cnt, b.pop_back();
        }
        // at least one of cur_cnt nyala, sisanya terserah
        // (powmod(2, cur_cnt) - 1) * powmod(2, cnt - cur_cnt)
        res[x] = (1ll * (powmod(2, cur_cnt) - 1) * powmod(2, cnt - cur_cnt)) % mod;
    }
    ll out = 0;
    for(int i = 1; i <= n; ++i) {
        out += (res[i] * ori[i]) % mod;
    }
    cout << out % mod << endl;
    // a[i] distinct gampang
    // case sulit: a[i] duplikat
    // to avoid: buat jadi ga duplikat (klo sama di pisah)
    // nanti convert di akhir
    return 0;
}