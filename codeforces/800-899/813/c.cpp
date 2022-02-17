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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> edges[n + 1];
    bool vis[n + 1];
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    int dist;
    int par[n + 1];
    int distances[n + 1];
    function<void(int, int)> find_dist = [&] (int nd, int depth) -> void {
        vis[nd] = 1;
        if(nd == x)
            dist = depth;
        distances[nd] = depth;
        for(auto i : edges[nd])
            if(!vis[i])
                par[i] = nd, find_dist(i, depth + 1);
    };
    memset(vis, 0, sizeof(vis));
    find_dist(1, 0);
    int tmp = dist;
    dist = dist / 2 + dist % 2 - 1;
    int mid = x;
    for(int i = 0; i < dist; ++i)
        mid = par[mid];
    int res = 0, node;
    function<void(int, int)> max_dist = [&] (int nd, int d) -> void {
        vis[nd] = 1;
        if(d >= res)
            node = nd, res = d;
        for(auto i : edges[nd]) 
            if(i != par[nd])
                max_dist(i, d + 1);
    };
    memset(vis, 0, sizeof(vis));
    max_dist(mid, 0);
    //cout << mid << " " << res << " " << node << endl;
    cout << 2 * distances[node] << endl;
    return 0;
}