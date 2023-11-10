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
const int lim = 1e5 + 5;
vector<int> edges[lim];
int subtree[lim];
void dfs(int nd) {
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i])
            dfs(i), subtree[nd] += subtree[i];
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    // root tiap gerai
    // cari sum of absolute difference with every other floor
    // cari sum of distance to all nodes
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    int k;
    cin >> k;
    vector<int> floors;
    for(int i = 1; i <= k; ++i) {
        int a, b;
        cin >> a >> b;
        floors.pb(a);
        ++subtree[b];
    }
    dfs(1);
    vector<pair<int, int>> s;
    for(int i = 1; i <= n; ++i)
        s.pb(mp(subtree[i], i));
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    long long res = 0;
    sort(floors.begin(), floors.end());
    for(auto i : floors) {
        res += abs(i - floors[floors.size() / 2]);
    }
    int nx = 1;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i].fi >= n / 2)
            nx = s[i].se;
        else
            break;
    }
    memset(vis, 0, sizeof(vis));
    memst(subtree, 0, sizeof(subtree));
    
    return 0;
}