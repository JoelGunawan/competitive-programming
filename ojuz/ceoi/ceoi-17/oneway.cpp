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
const int lim = 1e5 + 5;
// dsu struct
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
vector<pair<int, int>> edges[lim];
int disc[lim], low[lim], t = 0;
vector<int> bridge_id;
void dfs(int nd, int pr = -1) {
    disc[nd] = low[nd] = ++t;
    for(auto i : edges[nd]) {
        if(i.se == pr) {
            continue;
        }
        else if(disc[i.fi] == -1) {
            // undiscovered edge
            dfs(i.fi, i.se);
            low[nd] = min(low[nd], low[i.fi]);
            // check bridge
            if(disc[nd] < low[i.fi]) {
                // case if bridge
                bridge_id.pb(i.se);
            }
        }
        else {
            // back edge
            low[nd] = min(low[nd], disc[i.fi]);
        }
    }
}
// generate subtree count of start/ends and memo par
int st[lim], en[lim], par[lim];
bool vis[lim];
vector<int> bridge_edges[lim];
void bridge_dfs(int nd) {
    vis[nd] = 1;
    for(auto i : bridge_edges[nd]) {
        if(!vis[i]) {
            bridge_dfs(i);
            st[nd] += st[i];
            en[nd] += en[i];
            par[i] = nd;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // observe that if an edge is not a bridge, then the edge can face both directions (because it is part of a cycle)
    // therefore we only need to mark the bridges. To do this, we can create a bridge tree
    int n, m;
    cin >> n >> m;
    pair<int, pair<int, int>> adj[m + 1];
    for(int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[i] = (mp(i, mp(a, b)));
        edges[a].pb(mp(b, i));
        edges[b].pb(mp(a, i));
    }
    memset(disc, -1, sizeof(disc));
    memset(low, -1, sizeof(low));
    for(int i = 1; i <= n; ++i) {
        if(disc[i] == -1)
            dfs(i);
    }
    int p;
    cin >> p;
    vector<pair<int, int>> v;
    for(int i = 1; i <= p; ++i) {
        // there exists a road from x -> y
        // which means, we need to mark every bridge from x to y as used
        int x, y;
        cin >> x >> y;
        v.pb(mp(x, y));
    }
    // observe: because there is guaranteed to be a solution. For each bridge that connects A and B,
    // we can find the count of start/end of pairings from A and from B. 
    // If A has more starts, therefore the edge must be A -> B
    // else it must be B -> A
    // easiest way to create a bridge tree is using DSU
    sort(bridge_id.begin(), bridge_id.end());
    disjoint_set dsu;
    for(int i = 1; i <= m; ++i) {
        if(!binary_search(bridge_id.begin(), bridge_id.end(), adj[i].fi)) {
            // not a bridge edge
            dsu.merge(adj[i].se.fi, adj[i].se.se);
        }
    }
    for(int i = 1; i <= m; ++i) {
        // because of some problems, we have to do this in a for loop after the first binary search
        // try to think about it
        if(binary_search(bridge_id.begin(), bridge_id.end(), adj[i].fi)) {
            // is a bridge edge
            bridge_edges[dsu.fh(adj[i].se.fi)].pb(dsu.fh(adj[i].se.se));
            bridge_edges[dsu.fh(adj[i].se.se)].pb(dsu.fh(adj[i].se.fi));
        }
    }
    for(auto i : v) {
        ++st[dsu.fh(i.fi)];
        ++en[dsu.fh(i.se)];
    }
    for(int i = 1; i <+ n; ++i) {
        if(!vis[dsu.fh(i)])
            bridge_dfs(dsu.fh(i));
    }
    // interpret res as result array of direction as one of:
    // - 0: B
    // - 1: L
    // - 2: R
    int res[m + 1];
    memset(res, -1, sizeof(res));
    for(int i = 1; i <= m; ++i) {
        if(binary_search(bridge_id.begin(), bridge_id.end(), adj[i].fi)) {
            int x = dsu.fh(adj[i].se.fi), y = dsu.fh(adj[i].se.se);
            if(par[x] == y) {
                if(st[x] > en[x]) {
                    // x -> y
                    res[i] = 2;
                }
                else if(st[x] == en[x]) {
                    // x <=> y
                    res[i] = 0;
                }
                else {
                    // y -> x
                    res[i] = 1;
                }
            }
            else {
                if(st[y] > en[y]) {
                    // y -> x
                    res[i] = 1;
                }
                else if(st[y] == en[y]) {
                    // x <=> y
                    res[i] = 0;
                }
                else {
                    // x -> y
                    res[i] = 2;
                }
            }
        }
        else {
            res[i] = 0;
        }
    }
    for(int i = 1; i <= m; ++i) {
        if(res[i] == 0)
            cout << 'B';
        else if(res[i] == 1)
            cout << 'L';
        else if(res[i] == 2)
            cout << 'R';
        else
            assert(false);
    }
    cout << endl;
    return 0;
}