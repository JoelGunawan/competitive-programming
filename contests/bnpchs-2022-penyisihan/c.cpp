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
const int lim = 2e5 + 5;
vector<int> edges[lim];
int par[18][lim], depth[lim];
bool vis[lim];
void dfs(int nd) {
    vis[nd] = 1;
    int tmp = 1, tmp2 = par[tmp - 1][nd];
    while(tmp < 18 && tmp2 != 0)
        par[tmp][nd] = par[tmp - 1][tmp2], tmp2 = par[tmp][nd], ++tmp;
    for(auto i : edges[nd]) {
        //cout << i << endl;
        if(!vis[i])
            par[0][i] = nd, depth[i] = depth[nd] + 1, dfs(i);
    }
}
int lca(int u, int v) {
    // setarakan depth dulu
    if(depth[u] < depth[v])
        swap(u, v);
    for(int i = 17; i >= 0; --i) {
        if(depth[par[i][u]] >= depth[v])
            u = par[i][u];
    }
    if(u == v)
        return u;
    for(int i = 17; i >= 0; --i) {
        if(par[i][u] != par[i][v])
            u = par[i][u], v = par[i][v];
    }
    return par[0][u];
}
int dist(int u, int v) {
    int tmp = lca(u, v);
    //cout << u << " " << v << " " << abs(depth[u] - depth[tmp]) + abs(depth[v] - depth[tmp]) << endl;
    return abs(depth[u] - depth[tmp]) + abs(depth[v] - depth[tmp]);
}
int memo[2][2][lim], nd[2][lim], m;
int dp(bool pos, bool choose, int day) {
    if(day == m)
        return 0;
    if(memo[pos][choose][day] != -2e9)
        return memo[pos][choose][day];
    int res = 0;
    if(choose)
        memo[pos][choose][day] 
        = max(dist(nd[pos][day], nd[pos][day + 1]) + dp(pos, !choose, day + 1) - dist(nd[!pos][day], nd[!pos][day + 1])
        , dist(nd[pos][day], nd[!pos][day + 1]) + dp(!pos, !choose, day + 1) - dist(nd[!pos][day], nd[pos][day + 1]));
    else {
        memo[pos][choose][day] 
        = min(dist(nd[pos][day], nd[pos][day + 1]) + dp(pos, !choose, day + 1) - dist(nd[!pos][day], nd[!pos][day + 1])
        , dist(nd[pos][day], nd[!pos][day + 1]) + dp(!pos, !choose, day + 1) - dist(nd[!pos][day], nd[pos][day + 1]));
    }
    //cout << (int)pos << " " << (int)choose << " " << day << " " << memo[pos][choose][day] << endl;
    return memo[pos][choose][day];
}
int main() {
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            for(int k = 0; k < lim; ++k)
                memo[i][j][k] = -2e9;
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dfs(1);
    depth[0] = -1;
    cin >> m;
    nd[0][0] = 1, nd[1][0] = 1;
    for(int i = 1; i <= m; ++i) {
        cin >> nd[0][i] >> nd[1][i];
    }
    dp(0, 1, 0);
    if(dp(0, 1, 0) == 0)
        cout << "Draw 0" << endl;
    else if(dp(0, 1, 0) > 0)
        cout << "Djowen" << " " << dp(0, 1, 0) << endl;
    else
        cout << "Djonatan" << " " << -dp(0, 1, 0) << endl;
    // basically, choose distance maks
    // dp gampang, tinggal pakai lca buat cari dist between 2 nodes
    return 0;
}