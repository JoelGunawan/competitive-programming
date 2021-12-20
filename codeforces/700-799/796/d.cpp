#include <bits/stdc++.h>
//#define endl "\n"
#define pb push_back
#define fi first
#define se second
#define lim 300001
using namespace std;
bool add[lim], vis[lim];
int n, k, d;
vector<int> edges[lim];
set<int> ans;
set<pair<pair<int, int>, int>> a;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(vis, 0, sizeof(vis));
    memset(add, 0, sizeof(add));
    cin >> n >> k >> d;
    int pol = 0;
    queue<pair<int, int>> bfs;
    for(int i = 0; i < k; ++i)
    {
        int p;
        cin >> p;
        //cout << p << endl;
        if(!add[p])
            bfs.push({p, p});
        add[p] = 1;
    }
    //cout << "TEST" << endl;
    for(int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        //cout << u << " " << v << endl;
        edges[u].pb(v);
        edges[v].pb(u);
        a.insert({{min(u, v), max(u, v)}, i + 1});
    }
    // do a multi source bfs
    // where if there is an intersection of 2 police stations
    // remove an edges
    while(bfs.size() > 0)
    {
        pair<int, int> cur = bfs.front();
        bfs.pop();
        if(vis[cur.fi])
        {
            // remove the current edge between cur.fi and cur.se
            ans.insert((*a.lower_bound({{min(cur.fi, cur.se), max(cur.fi, cur.se)}, 0})).se);
            continue;
        }
        vis[cur.fi] = 1;
        // continue the bfs
        for(int i = 0; i < edges[cur.fi].size(); ++i)
        {
            if(!vis[edges[cur.fi][i]])
                bfs.push({edges[cur.fi][i], cur.fi});
        }
    }
    cout << ans.size() << endl;
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}