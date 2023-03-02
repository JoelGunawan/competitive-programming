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
const int lim = 5e4 + 5;
vector<int> edges[lim];
bool vis[lim];
int dp[lim][505], k;   
ll dfs(int nd) {
    vis[nd] = 1;
    ll res = 0;
    dp[nd][0] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            res += dfs(i);
            for(int j = 0; j < k; ++j)
                res += 1ll * dp[nd][j] * dp[i][k - 1 - j];
            for(int j = 1; j <= k; ++j)
                dp[nd][j] += dp[i][j - 1];
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n >> k;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    cout << dfs(1) << endl;;
    return 0;
}