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
vector<int> edges[200001];
int min_time[200001], dist[200001];
bool vis[200001];
void dfs(int nd, int depth) {
    vis[nd] = 1;
    dist[nd] = depth;
    for(auto i : edges[nd])
        if(!vis[i])
            dfs(i, depth + 1);
}
void tc() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i <= n; ++i)
        min_time[i] = INT_MAX;
    int x[k];
    for(int i = 0; i < k; ++i)
        cin >> x[i];
    for(int i = 0; i <= n; ++i)
        edges[i].clear();
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    queue<pair<int, int>> bfs;
    for(int i = 0; i < k; ++i)
        bfs.push(mp(0, x[i]));
    fill(vis, vis + n + 1, 0);
    while(bfs.size() > 0) {
        pair<int, int> cur = bfs.front();
        int nd = cur.se, depth = cur.fi;
        bfs.pop();
        min_time[nd] = depth;
        // do code
        if(vis[nd])
            continue;
        else {
            vis[nd] = 1;
            for(auto i : edges[nd]) {
                if(!vis[i]) {
                    bfs.push(mp(depth + 1, i));
                }
            }
        }
    }
    fill(vis, vis + n + 1, 0);
    dfs(1, 0);
    for(int i = 2; i <= n; ++i)
        if(edges[i].size() == 1 && min_time[i] > dist[i]) {
            cout << "YES" << endl;
            return;
        }
    cout << "NO" << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)  
        tc();
    return 0;
}