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
ll sqr(ll a) {
    return a * a;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    pair<ll, ll> a[k];
    for(int i = 0; i < k; ++i)
        cin >> a[i].fi >> a[i].se;
    // cari dist dr top to bottom
    bool vis[k];
    memset(vis, 0, sizeof(vis));
    ll dist[k];
    for(int i = 0; i < k; ++i) {
        dist[i] = sqr(m - a[i].se);
    }
    for(int i = 0; i < k; ++i) {
        // choose minimum, terus visit minimum
        pair<ll, int> mn = mp((ll)1e18, 0);
        for(int j = 0; j < k; ++j) {
            if(!vis[j])
                mn = min(mn, mp(dist[j], j));
        }
        // kalo ga visited
        vis[mn.se] = 1;
        for(int j = 0; j < k; ++j) {
            if(!vis[j]) {
                dist[j] = min(dist[j], max(mn.fi, sqr(a[mn.se].fi - a[j].fi) + sqr(a[mn.se].se - a[j].se)));
            }
        }
    }
    ll res = 1e18;
    for(int i = 0; i < k; ++i) {
        res = min(res, max(dist[i], sqr(a[i].se)));
    }
    cout << fixed << setprecision(10) << sqrt(res) / 2.0 << endl;
    return 0;
}