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
const int lim = 300001;
vector<int> edges[lim], inv_edges;
bool vis[lim];
vector<int> cur, topo;
void dfs(int nd) {
    vis[nd] = 1;
    cur.pb(nd);
    if(edges[nd].size() > 0)
        dfs(edges[nd][0]);
}
int prev_dp[lim], next_dp[lim];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        inv_edges[v].pb(u);
    }
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            dfs(i);
            for(int j = cur.size() - 1; j >= 0; --j)
                topo.pb(cur[j]);
            cur.clear();
        }
    }
    
    return 0;
}