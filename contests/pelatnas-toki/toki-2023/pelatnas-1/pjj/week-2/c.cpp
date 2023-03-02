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
const int lim = 2e5 + 5, lim2 = 17;
vector<int> edges[lim];
int par[lim][lim2 + 1], depth[lim];
bool vis[lim];
void dfs(int nd) {
    int tmp = 0, tmp2 = par[nd][0];
    while(tmp2 != 0) {
        tmp2 = par[nd][tmp + 1] = par[tmp2][tmp];
        ++tmp;
    }
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            par[i][0] = nd;
            depth[i] = depth[nd] + 1;
            dfs(i);
        }
    }
}
int lca(int u, int v) {
    if(depth[v] > depth[u]) {
        swap(u, v);
    }
    for(int i = lim2; i >= 0; --i) {
        if(depth[par[u][i]] >= depth[v])
            u = par[u][i];
    }
    if(u == v)  
        return u;
    for(int i = lim2; i >= 0; --i) {
        if(par[u][i] != par[v][i])
            u = par[u][i], v = par[v][i];
    }
    return par[u][0];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    //t = 1;
    for(int i = 1; i <= t; ++i) {
        cout << "Case " << i << ":" << endl;
        int n;
        //cin >> n;
        cin >> n;
        for(int i = 0; i <= n; ++i) {
            edges[i].clear();
            vis[i] = 0;
            depth[i] = 0;
            for(int j = 0; j <= lim2; ++j)
                par[i][j] = 0;
        }
        bool in[n + 1];
        memset(in, 0, sizeof(in));
        for(int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            for(int j = 0; j < x; ++j) {
                int y;
                cin >> y;
                edges[i].pb(y);
                in[y] = 1;
            }
        }
        for(int i = 1; i <= n; ++i) {
            if(!in[i]) {
                depth[i] = 1;
                dfs(i);
            }
        }
        /*
        for(int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            edges[u].pb(v);
            edges[v].pb(u);
        }
        dfs(1);
        */
        /*
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= lim2; ++j)
                cout << par[i][j] << " ";
            cout << endl;
        }
        for(int i = 1; i <= n; ++i)
            cout << depth[i] << " ";
        cout << endl;
        */
        int m;
        cin >> m;
        while(m--) {
            int u, v;
            cin >> u >> v;
            int tmp = lca(u, v);
            cout << lca(u, v) << endl;
            //cout << depth[u] + depth[v] - 2 * depth[tmp] << endl;
        }
    }
    return 0;
}