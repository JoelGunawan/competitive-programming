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
void tc() {
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<pair<int, int>> pq;
    int x[k], d[k];
    for(int i = 0; i < k; ++i)
        cin >> x[i];
    for(int i = 0; i < k; ++i)
        cin >> d[i];
    for(int i = 0; i < k; ++i)
        pq.push(mp(d[i] - 1, x[i]));
    vector<int> edges[n + 1];
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    while(pq.size()) {
        int dist = pq.top().fi, nd = pq.top().se;
        pq.pop();
        if(vis[nd])
            continue;
        //cout << dist << " " << nd << endl;
        vis[nd] = 1;
        for(auto i : edges[nd]) {
            if(!vis[i] && dist != 0)
                pq.push(mp(dist - 1, i));
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // dijkstra by maximum distance remaining
    // fi -> max dist remaining
    // se -> node
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}