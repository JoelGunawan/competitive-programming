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
const int lim = 2e3 + 5;
vector<int> edges[lim];
bool vis[lim];
int par[11][lim], depth[lim];
void dfs(int nd) {
    vis[nd] = 1;
    int tmp = 0, tmp2 = par[0][nd];
    while(tmp2 != 0) {
        par[tmp][nd] = tmp2;
        tmp2 = par[tmp][tmp2], ++tmp;
    }
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            depth[i] = depth[nd] + 1;
            par[0][i] = nd;
            dfs(i);
        }
    }
}
int lca(int x, int y) {
    if(depth[x] > depth[y])
        swap(x, y);
    for(int i = 10; i >= 0; --i) {
        if(depth[y] - depth[x] >= (1 << i)) {
            y = par[i][y];
            //cout << "DEPTH " <<depth[x] << " " << depth[y] << endl;
        }
    }
    //cout << "LCA " << x << " " << y << endl;
    if(x == y)
        return x;
    for(int i = 10; i >= 0; --i) {
        if(par[i][x] != par[i][y])
            x = par[i][x], y = par[i][y];
    }
    return par[0][x];
}
int dp[lim][lim];
string s;
int get(int x, int y) {
    //cout << x << " " << y << endl;
    if(x == y)
        return 1;
    //cout << x << " " << y << endl;
    if(dp[x][y] != -1)
        return dp[x][y];
    //cout << "TEST" << endl;
    int tmp = lca(x, y), xchild;
    if(tmp == x || tmp == y) {
        //cout << "TEST" << endl;
        if(tmp == y)
            swap(x, y);
        xchild = y;
        //cout << xchild << " ";
        for(int i = 10; i >= 0; --i) {
            if(depth[par[i][xchild]] > depth[x])
                xchild = par[i][xchild];
        }
        //cout << endl;
        if(par[0][y] == x) {
            if(s[x] == s[y])
                dp[x][y] = 2;
            else
                dp[x][y] = 1;
        }
        else {
            dp[x][y] = max({1, get(xchild, y), get(x, par[0][y])});
            if(s[x] == s[y])
                dp[x][y] = max(dp[x][y], get(xchild, par[0][y]) + 2);
        }
    }
    else {
        xchild = par[0][x];
        dp[x][y] = max({1, get(par[0][x], y), get(x, par[0][y])});
        if(s[x] == s[y])
            dp[x][y] = max(dp[x][y], get(par[0][x], par[0][y]) + 2);
    }
    //cout << lca(x, y) << " " << xchild << " " << par[0][y] << " " << s[x] << " " << s[y] << " " << x << " " << y << " " << dp[x][y] << endl;
    return dp[y][x] = dp[x][y];
}
void tc() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j)
            dp[i][j] = -1;
    }
    for(int i = 0; i <= 10; ++i) {
        for(int j = 1; j <= n; ++j)
            par[i][j] = 0;
    }
    for(int i = 1; i <= n; ++i) {
        depth[i] = 0;
        vis[i] = 0;
        edges[i].clear();
    }
    cin >> s;
    s = " " + s;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dfs(1);
    int res = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            res = max(res, get(i, j));
        }
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}