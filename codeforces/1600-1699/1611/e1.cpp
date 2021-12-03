#include <bits/stdc++.h>
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pf push_front
#define ll long long
#define fi first
#define se second
#pragma GCC optimize("Ofast")
using namespace std;
void test_case()
{
    int n, k;
    cin >> n >> k;
    int x[k];
    for(int i = 0; i < k; ++i)
        cin >> x[i];
    // do 2 BFS, where we try to find the earliest an attacker can get to a node and the earliest vlad can get to a node
    // the first BFS fills the earlies attacker
    // the second BFS finds whether vlad can reach a leaf safely
    vector<int> edges[n + 1];
    for(int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    // first is time, second is node
    queue<pair<int, int>> bfs;
    for(int i = 0; i < k; ++i)
        bfs.push({0, x[i]});
    bool vis[n + 1]; memset(vis, 0, sizeof(vis));
    int dist[n + 1]; dist[0] = 0;
    while(bfs.size() > 0)
    {
        pair<int, int> cur = bfs.front();
        bfs.pop();
        if(vis[cur.se])
            continue;
        vis[cur.se] = 1;
        dist[cur.se] = cur.fi;
        for(int i = 0; i < edges[cur.se].size(); ++i)
            if(!vis[edges[cur.se][i]])
                bfs.push({cur.fi + 1, edges[cur.se][i]});
    }
    memset(vis, 0, sizeof(vis));
    bool ans = 0;
    bfs.push({0, 1});
    while(bfs.size() > 0)
    {
        pair<int, int> cur = bfs.front();
        bfs.pop();
        // check for invalid (including an attacker already occupies it)
        if(vis[cur.se])
            continue;
        vis[cur.se] = 1;
        // an answer exists
        if(edges[cur.se].size() == 1 && cur.se != 1)
        {
            ans = 1;
            break;
        }
        // find other neighboring nodes
        for(int i = 0; i < edges[cur.se].size(); ++i)
            if(!vis[edges[cur.se][i]] && dist[edges[cur.se][i]] > cur.fi + 1)
                bfs.push({cur.fi + 1, edges[cur.se][i]});
    }
    if(ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}