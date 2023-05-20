#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int lim = 1e5 + 5;
bool vis[lim];
int par[17][lim], depth[lim], subtree[lim];
vector<int> edges[lim], child[lim];
void dfs(int nd) {
    vis[nd] = 1;
    for(int i = 1; i < 17; ++i)
        par[i][nd] = par[i - 1][par[i - 1][nd]];
    subtree[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            depth[i] = depth[nd] + 1;
            par[0][i] = nd;
            dfs(i);
            subtree[nd] += subtree[i];
            child[nd].push_back(i);
        }
    }
}
int lca(int u, int v) {
    if(depth[u] > depth[v])
        swap(u, v);
    // v bigger depth
    for(int i = 16; i >= 0; --i) {
        if(depth[v] - (1 << i) >= depth[u])
            v = par[i][v];
    }
    if(u == v)
        return u;
    for(int i = 16; i >= 0; --i) {
        if(par[i][v] != par[i][u])
            u = par[i][u], v = par[i][v];
    }
    return par[0][u];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // coding lca
    // cari subtree size di lca
    // ada beberapa case
    // case dimana lca merupakan equi dist
    // bisa ke semua subtree dan par kecuali yg mengandung lca
    // case dimana lca bukan merupakan equi dist
    // bisa ke semua subtree kecuali yg mengandung lca
    depth[1] = 1;
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1);
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        int lc = lca(x, y);
        //cout << x << " " << y << " " << lc << endl;
        if((depth[x] + depth[y] - 2 * depth[lc]) & 1) {
            cout << 0 << endl;
            continue;
        }
        else if(x == y) {
            cout << n << endl;
            continue;
        }
        if(depth[x] < depth[y])
            swap(x, y);
        // x itu max depth
        if(depth[y] == depth[x]) {
            // intersect di mid, boleh ke par
            for(int i = 16; i >= 0; --i) {
                if(depth[y] - (1 << i) > depth[lc])
                    y = par[i][y];
                if(depth[x] - (1 << i) > depth[lc])
                    x = par[i][x];
            }
            cout << subtree[1] - subtree[x] - subtree[y] << endl;
        }
        else {
            // intersect di random point, harus ke child doang
            int target = depth[lc] + (depth[x] - depth[y]) / 2;
            for(int i = 16; i >= 0; --i) {
                if(depth[par[i][x]] > target)
                    x = par[i][x];
            }
            cout << subtree[par[0][x]] - subtree[x] << endl;
        }
    }
}