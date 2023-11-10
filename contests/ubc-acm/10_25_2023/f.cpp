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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, t;
    cin >> n >> t;
    // fi -> dest
    // se -> key moment number
    vector<pair<int, int>> edges[n + 1];
    for(int i = 1; i <= t; ++i) {
        int m;
        cin >> m;
        for(int j = 1; j <= m; ++j) {
            int u, v;
            cin >> u >> v;
            edges[u].pb(mp(v, i));
            edges[v].pb(mp(u, i));
        }
    }
    int k;
    cin >> k;
    vector<int> occur[t + 1];
    for(int i = 1; i <= k; ++i) {
        int x;
        cin >> x;
        occur[x].pb(i);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // fi -> dist
    // se -> node
    pq.push(mp(0, 1));
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    while(pq.size()) {
        int dist = pq.top().fi, nd = pq.top().se;
        pq.pop();
        if(vis[nd])
            continue;
        vis[nd] = 1;
        if(nd == n) {
            cout << dist << endl;
            return 0;
        }
        for(auto i : edges[nd]) {
            if(!vis[i.fi] && ub(occur[i.se].begin(), occur[i.se].end(), dist) != occur[i.se].end()) {
                pq.push(mp(*ub(occur[i.se].begin(), occur[i.se].end(), dist), i.fi));
            }
        }
    }
    cout << -1 << endl;
    return 0;
}