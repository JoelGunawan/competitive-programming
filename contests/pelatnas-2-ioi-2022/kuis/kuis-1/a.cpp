#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ins insert
#define ll long long
using namespace std;
vector<int> edges[100005], bridge_tree[100005];
int t = 0;
int mod = 1e9 + 7;
bool vis[100005];
int disc[100005], low[100005];
void dfs(int nd, int prev = -1) {
    disc[nd] = low[nd] = ++t;
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(vis[i]) {
            if(i != prev)
                low[nd] = min(low[nd], disc[i]);
        }
        else {
            dfs(i, nd);
            low[nd] = min(low[nd], low[i]);
        }
    }
}
struct disjoint_set {
    int head[100005], size[100005];
    disjoint_set() {
        fill(size, size + 100005, 1);
        memset(head, -1, sizeof(head));
    }
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int a, int b) {
        int x = find_head(a), y = find_head(b);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            size[x] += size[y], head[y] = x;
        }
        return x != y;
    }
};
ll subtree[100005];
int par[100005];
ll bridge_dfs(int nd, int prev = -1) {
    vis[nd] = 1;
    subtree[nd] = 1;
    par[nd] = prev;
    for(auto i : bridge_tree[nd]) {
        if(!vis[i])
            subtree[nd] = (subtree[nd] * (bridge_dfs(i, nd) + 1)) % mod;
    }
    return subtree[nd];
}
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // find bridges
    // make a bridge tree
    // find count of unique bridge tree nodes for each node
    // check how many combinations of mergers there are
    // algo bridge tree use dfs
    // use low and disc
    // kalo root
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    disjoint_set dsu;
    dfs(1);
    for(int i = 1; i <= n; ++i) {
        for(auto j : edges[i]) {
            // is bridge tree edge
            if(disc[i] < disc[j] && low[j] > disc[i])
                continue;
            // is bridge tree edge
            else if(disc[i] > disc[j] && low[i] > disc[j])
                continue;
            else {
                dsu.merge(i, j);               
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(auto j : edges[i]) {
            // change to less than or equal to?
            if((disc[i] < disc[j] && low[j] > disc[i]) || (disc[i] > disc[j] && low[i] > disc[j])) {
                bridge_tree[dsu.find_head(i)].pb(dsu.find_head(j));    
            }
        }
    }
    for(int it = 0; it < q; ++it) {
        int k;
        cin >> k;
        memset(vis, 0, sizeof(vis));
        memset(subtree, 0, sizeof(subtree));
        cout << bridge_dfs(dsu.find_head(k)) << endl;
    }
}