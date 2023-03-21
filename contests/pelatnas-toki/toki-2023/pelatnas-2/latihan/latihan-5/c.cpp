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
const int lim = 1e5 + 5;
struct query {
    int l, r, x, y, z, id;
};
struct disjoint_set {
    int sz[lim], h[lim];
    disjoint_set() {
        memset(h, -1, sizeof(h));
        fill(sz, sz + lim, 1);
    }
    int fh(int nd) {
        return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
    }
    void merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y];
            h[y] = x;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    int n, m;
    cin >> n >> m;
    // fi.fi = l, fi.se = r, se = query_num
    vector<query> queries[20][m + 1];
    pair<int, int> edges[m + 1];
    for(int i = 1; i <= m; ++i) {
        cin >> edges[i].fi >> edges[i].se;
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        query tmp;
        tmp.x = x, tmp.y = y, tmp.z = z, tmp.l = 1, tmp.r = m, tmp.id = i;
        queries[0][(tmp.l + tmp.r) / 2].pb(tmp);
    }
    int ans[q];
    memset(ans, -1, sizeof(ans));
    disjoint_set dsu;
    for(int it = 0; it < 19; ++it) {
        memset(dsu.h, -1, sizeof(dsu.h));
        fill(dsu.sz, dsu.sz + lim, 1);
        for(int i = 1; i <= m; ++i) {
            dsu.merge(edges[i].fi, edges[i].se);
            for(auto j : queries[it][i]) {
                if(j.l > j.r)
                    continue;
                int cur = 0, mid = i;
                if(dsu.fh(j.x) == dsu.fh(j.y))
                    cur = dsu.sz[dsu.fh(j.x)];
                else
                    cur = dsu.sz[dsu.fh(j.x)] + dsu.sz[dsu.fh(j.y)];
                if(cur >= j.z) {
                    ans[j.id] = mid;
                    j.r = mid - 1;
                }
                else {
                    j.l = mid + 1;
                }
                queries[it + 1][(j.l + j.r) / 2].push_back(j);
                //cout << "OUTPUT " << j.id << " " << j.l << " " << j.r << " " << cur << endl;
            }
        }
    }
    for(auto i : ans)
        cout << i << endl;
    return 0;
}