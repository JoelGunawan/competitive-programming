// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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
void tc() {
    int n, k;
    cin >> n >> k;
    vector<int> edges[n + 5];
    for(int i = 1; i <= n; ++i)
        edges[i] = vector<int>();
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    if(k == 0) {
        cout << n << endl;
        return;
    }
    else if(n == 1) {
        cout << 0 << endl;
        return;
    }
    // fi -> node, se -> distance
    int edge_cnt[n + 1];
    memset(edge_cnt, 0, sizeof(edge_cnt));
    queue<pair<int, int>> bfs;
    for(int i = 1; i <= n; ++i) {
        edge_cnt[i] = edges[i].size();
        if(edges[i].size() <= 1)
            bfs.push(mp(i, 1));
    }
    bool vis[n + 5];
    memset(vis, 0, sizeof(vis));
    int res = 0;
    while(bfs.size() > 0) {
        int node = bfs.front().fi, dist = bfs.front().se;
        bfs.pop();
        if(vis[node])
            continue;
        vis[node] = 1;
        ++res;
        if(dist + 1 <= k) {
            for(auto i : edges[node])
                if(!vis[i]) {
                    --edge_cnt[i];
                    if(edge_cnt[i] <= 1)
                        bfs.push(mp(i, dist + 1));                   
                }
        }
    }
    cout << n - res << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}