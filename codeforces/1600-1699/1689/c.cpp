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
vector<int> edges[lim];
bool vis[lim];
int dfs(int nd, int d = 0) {
    vis[nd] = 1;
    int cnt = 0, res = 1e9;
    for(auto i : edges[nd]) {
        if(!vis[i])
            res = min(res, dfs(i, d + 2)), ++cnt;
    }
    if(cnt == 0)
        return d + 1;
    else if(cnt == 1)
        return d + 2;
    return res;
}
void tc() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        edges[i].clear(), vis[i] = 0;
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    cout << n - dfs(1) << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    edges[0].pb(1);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}