#include <bits/stdc++.h>
#define ll long long
//#define endl "\n"
#define pb push_back
#define fi first
#define se second
using namespace std;
vector<pair<int, int>> edges[100000];
int main()
{
    int n, m, l, u;
    cin >> n >> m >> l >> u;
    for(int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].pb({w, v});
        edges[v].pb({w, u});
    }
    for(int i = 1; i <= n; ++i)
        sort(edges[i].begin(), edges[i].end());
    priority_queue<pair<int, int>> dj;
    int res = 0;
    dj.push({-0, 0});
    bool vis[n]; memset(vis, 0, sizeof(vis));
    while(dj.size() > 0)
    {
        pair<int, int> cur = dj.top();
        dj.pop();
        cur.fi = -cur.fi;
        if(vis[cur.se])
            continue;
        vis[cur.se] = 1;
        for(auto edge : edges[cur.se])
        {
            if(!vis[(edge.se)])
            {
                if(2 * (cur.fi + edge.fi) < u)
                    dj.push({-(cur.fi + edge.fi), edge.se});
                if(2 * (cur.fi) < u)
                    ++res;
            }
        }
    }
    cout << res << endl;
}