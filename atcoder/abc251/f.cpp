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
bool vis[lim];
vector<pair<int, int>> ans1, ans2;
void dfs(int nd) {
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            ans1.pb(mp(nd, i));
            dfs(i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dfs(1);
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;
    vis[1] = 1;
    for(auto i : edges[1])
        q.push(mp(i, 1));
    while(q.size()) {
        int nd = q.front().fi, prev = q.front().se;
        q.pop();
        if(vis[nd])
            continue;
        vis[nd] = 1;
        ans2.pb(mp(nd, prev));
        for(auto i : edges[nd]) {
            if(!vis[i])
                q.push(mp(i, nd));
        }
    }
    for(auto i : ans1)
        cout << i.fi << " " << i.se << endl;
    for(auto i : ans2)
        cout << i.fi << " " << i.se << endl;
    return 0;
}