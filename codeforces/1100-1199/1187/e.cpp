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
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int lim = 2e5 + 5;
vector<int> edges[lim];
bool vis[lim];
long long subtree[lim], res[lim];
void dfs_init(int nd) {
    vis[nd] = 1, subtree[nd] = 1, res[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            dfs_init(i);
            subtree[nd] += subtree[i];
            res[nd] += res[i] + subtree[i];
        }
    }
}
long long dfs(int nd, long long from_par) {
    vis[nd] = 1;
    long long ret = from_par;
    for(auto i : edges[nd])
        if(!vis[i])
            ret = max(ret, dfs(i, from_par + subtree[1] - 2 * subtree[i]));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dfs_init(1);
    memset(vis, 0, sizeof(vis));
    cout << dfs(1, res[1]) << endl;
    return 0;
}