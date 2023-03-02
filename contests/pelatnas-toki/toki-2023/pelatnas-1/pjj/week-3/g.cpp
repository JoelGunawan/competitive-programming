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
const int lim = 3e5 + 5;
int low[lim], disc[lim], t = 0;
vector<pair<int, int>> bridge_edges;
vector<pair<int, int>> edges[lim];
void dfs(int nd, int par) {
    low[nd] = disc[nd] = ++t;
    for(auto i : edges[nd]) {
        if(disc[i.fi] == 0) {
            dfs(i.fi, nd);
            if(low[i.fi] > disc[nd]) {
                bridge_edges.pb(mp(min(nd, i.fi), max(nd, i.fi)));
            }
            low[nd] = min(low[i.fi], low[nd]);
        }
        else if(i.fi != par) {
            low[nd] = min(disc[i.fi], low[nd]);
        }
    }
    //cout << nd << " " << disc[nd] << " " << low[nd] << endl;
}

struct disjoint_set {
    int head[lim], sz[lim];
    bool arti[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(sz, sz + lim, 1);
        memset(arti, 0, sizeof(arti));
    }
    int fh(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    void merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            head[y] = x;
            sz[x] += sz[y];
            arti[x] |= arti[y];
        }
    }
};

disjoint_set dsu;
vector<pair<int, int>> edges2[lim];
int o, d;
bool vis[lim];
int dfs2(int nd, bool x) {
    vis[nd] = 1;
    x |= dsu.arti[nd];
    //cout << nd << " " << x << endl;
    if(nd == d) {
        return x;
    }
    bool ans = 0;
    for(auto i : edges2[nd]) {
        if(!vis[i.fi])
            ans |= dfs2(i.fi, x | i.se);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    // create bridge tree, there has to be a bridge tree in the dfs between the origin and target island
    // find which edges are bridges
    pair<pair<int, int>, int> a[m + 1];
    for(int i = 1; i <= m; ++i) {
        cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
        edges[a[i].fi.fi].pb(mp(a[i].fi.se, a[i].se));
        edges[a[i].fi.se].pb(mp(a[i].fi.fi, a[i].se));
        if(a[i].fi.fi > a[i].fi.se) {
            swap(a[i].fi.fi, a[i].fi.se);
        }
    }            
    cin >> o >> d;
    dfs(1, 0);
    sort(bridge_edges.begin(), bridge_edges.end());
    vector<pair<pair<int, int>, int>> tmp;
    for(int i = 1; i <= m; ++i) {
        if(!binary_search(bridge_edges.begin(), bridge_edges.end(), a[i].fi)) {
            dsu.arti[dsu.fh(a[i].fi.fi)] |= a[i].se;
            dsu.merge(a[i].fi.fi, a[i].fi.se);
        }
        else {
            tmp.pb(mp(mp(a[i].fi.fi, a[i].fi.se), a[i].se));
        }
    }
    for(auto i : tmp) {
        edges2[dsu.fh(i.fi.fi)].pb(mp(dsu.fh(i.fi.se), i.se));
        edges2[dsu.fh(i.fi.se)].pb(mp(dsu.fh(i.fi.fi), i.se));
    }
    //cout << "BRIDGE" << endl;
    //for(auto i : bridge_edges)
    //    cout << i.fi << " " << i.se << endl;
    o = dsu.fh(o);
    d = dsu.fh(d);
    if(dfs2(o, 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}