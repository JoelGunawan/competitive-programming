#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define ins insert
#define pf push_front
#define ub upper_bound
#define lb lower_bound
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
// first is weight, second is node
vector<pii> edges[(int)1e5 + 1];
vector<int> blocks[(int)1e5 + 1];
int min_dist[(int)1e5 + 1];
bool vis[(int)1e5 + 1];
int main()
{
    fill(min_dist, min_dist + (int)1e5 + 1, 2e9);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    // shortest path with modifications
    for(int i = 0; i < m; ++i)
    {
        int u, v, l;
        cin >> u >> v >> l;
        edges[u].pb({l, v});
        edges[v].pb({l, u});
    }
    for(int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        vector<int> tmp(k);
        for(int j = 0; j < k; ++j)
            cin >> tmp[j];
        blocks[i] = tmp;
    }
    priority_queue<pii> pq;
    pq.push({-0, 1});
    while(pq.size() > 0)
    {
        if(vis[pq.top().second])
        {
            pq.pop();
            continue;
        }
        pii cur = pq.top();
        vis[cur.second] = 1;
        cur.first = -cur.first;
        pq.pop();
        while(binary_search(blocks[cur.second].begin(), blocks[cur.second].end(), cur.first))
            ++cur.first;
        for(int i = 0; i < edges[cur.second].size(); ++i)
        {
            if(cur.first + edges[cur.second][i].first < min_dist[edges[cur.second][i].second])
                pq.push({-(cur.first + edges[cur.second][i].first), edges[cur.second][i].second})
                , min_dist[edges[cur.second][i].second] = cur.first + edges[cur.second][i].first;
        }
    }
    if(min_dist[n] == 2e9)
        cout << -1 << endl;
    else
        cout << min_dist[n] << endl;
    return 0;
}