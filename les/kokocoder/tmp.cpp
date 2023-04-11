#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
#define pb push_back
#define endl "\n"
ll t, v, e, x, y, z;
vector<pii> adj[1010];
ll dist[1010];
bool vis[1010], ans;
priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    // bellman ford 
    // negative cycle finding (model dfs)
    // 
    while (t--)
    {
        memset(vis, 0, sizeof(vis));
        ans = false;
        cin >> v >> e;
        for(int i = 0; i <= v; ++i) {
            adj[i].clear();
        }   
        for (int i = 1; i <= e; i++)
        {
            cin >> x >> y >> z;
            adj[x].push_back(make_pair(y, z));
            adj[y].push_back(make_pair(x, z));
        }
        for (int i = 0; i <= v; i++)
        {
            dist[i] = 1e9;
        }
        pq.push(make_pair(0, make_pair(0, 0)));
        dist[0] = 0;
        vis[0] = true;
        int cnt = 0;
        while (!pq.empty() && cnt < 1e5)
        {
            ++cnt;
            ll ww = pq.top().fi;
            ll vv = pq.top().se.fi;
            ll pr = pq.top().se.se;
            //cout << ww << " " << vv << endl;
            pq.pop();
            if(ww != dist[vv])
                continue;
            vis[vv] = true;
            for (pii temp : adj[vv])
            {
                if(temp.fi == pr)
                    continue;
                ll a = temp.fi;
                ll b = temp.se;
                if (dist[a] > dist[vv] + b)
                {
                    dist[a] = dist[vv] + b;
                    pq.push(make_pair(dist[a], make_pair(a, vv)));
                }
            }
        }
        if (cnt == 1e5)
        {
            cout << "Pak Dengklek tidak mau pulang" << endl;
        }
        else if (!vis[v - 1])
        {
            cout << "Tidak ada jalan" << endl;
        }
        else
        {
            cout << dist[v - 1] << endl;
        }
    }
}