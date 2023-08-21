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
const int lim = 2e5 + 5;
struct disjoint_set {
    int h[lim], sz[lim];
    disjoint_set() {
        memset(h, -1, sizeof(h));
        fill(sz, sz + lim, 1);
    }
    int fh(int nd) {
        return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
    }
    bool merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y];
            h[y] = x;
        }
        return x != y;
    }
};
disjoint_set dsu;
void tc() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        dsu.h[i] = -1;
        dsu.sz[i] = 1;
    }
    int h[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> h[i];
    // find min height
    // paralel binser dsu, nanti cek max heightnya berapa (ga usah bs offline query biasa)
    // e -> maximum energy
    // coba connected
    vector<pair<int, pair<int, int>>> adj;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj.pb(mp(max(h[u], h[v]), mp(u, v)));
    }
    sort(adj.begin(), adj.end());
    int q;
    cin >> q;
    // fi.fi -> cost
    // fi.se -> query num
    // se.fi -> a
    // se.se -> b
    vector<pair<pair<int, int>, pair<int, int>>> query;
    for(int i = 1; i <= q; ++i) {
        int a, b, e;
        cin >> a >> b >> e;
        query.pb(mp(mp(h[a] + e, i), mp(a, b)));
    }
    sort(query.begin(), query.end());
    // query mulai dari paling kecil ke besar
    // nanti cek udh connected atau blum
    reverse(query.begin(), query.end());
    bool ans[q + 1];
    memset(ans, 0, sizeof(ans));
    for(auto i : adj) {
        while(query.size() && query.back().fi.fi < i.fi) {
            //cout << query.back().fi.se << " " << query.back().se.fi << " " << query.back().se.se << endl;
            ans[query.back().fi.se] = dsu.fh(query.back().se.fi) == dsu.fh(query.back().se.se);
            query.pop_back();
        }
        //cout << "MERGED " << i.se.fi << " " << i.se.se << endl;
        dsu.merge(i.se.fi, i.se.se);
    }
    while(query.size()) {
        ans[query.back().fi.se] = dsu.fh(query.back().se.fi) == dsu.fh(query.back().se.se);
        query.pop_back();
    }
    for(int i = 1; i <= q; ++i) {
        if(ans[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}