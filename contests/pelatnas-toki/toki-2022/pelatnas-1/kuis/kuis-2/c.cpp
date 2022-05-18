#include <bits/stdc++.h>
//#define endl "\n"
#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
using namespace std;
vector<pair<int, int>> edges[100001];
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, s, t, u, v;
    cin >> n >> m >> s >> t >> u >> v;
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].pb(mp(b, c));
        edges[b].pb(mp(a, c));
    }
    priority_queue<pair<ll, pair<int, int>>> dj;
    dj.push(mp(0, mp(s, s)));
    // subtask s = u
    ll min_dist[n + 1];
    vector<int> previous[n + 1];
    fill(min_dist, min_dist + n + 1, 1e18);
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    while(dj.size() > 0) {
        pair<ll, pair<int, int>> cur = dj.top();
        dj.pop();
        ll dist = -cur.fi, nd = cur.se.fi, prev = cur.se.se;
        if(dist == min_dist[nd])
            previous[nd].pb(prev);
        else if(dist < min_dist[nd]) {
            min_dist[nd] = dist;
            previous[nd].clear();
            previous[nd].pb(prev);
        }
        else
            continue;
        if(vis[nd])
            continue;
        vis[nd] = 1;
        for(auto i : edges[nd]) {
            if(!vis[i.fi]) {
                dj.push(mp(-(dist + i.se), mp(i.fi, nd)));
            }
        }
    }
    // dfs the previous
    bool short_path[n + 1];
    memset(short_path, 0, sizeof(short_path));
    function<void(int)> dfs = [&] (int nd) -> void {
        short_path[nd] = 1;
        for(auto i : previous[nd]) {
            if(i != nd) {
                dfs(i);
            }
        }
    };
    dfs(t);
    // find distance of v to any node in the shortest path
    priority_queue<pair<ll, int>> dijkstra;
    memset(vis, 0, sizeof(vis));
    dijkstra.push(mp(0, v));
    ll res;
    while(dijkstra.size() > 0) {
        ll dist = -dijkstra.top().fi, nd = dijkstra.top().se;
        dijkstra.pop();
        if(nd == u) {
            res = dist;
            break;
        }
        else if(vis[nd])
            continue;
        vis[nd] = 1;
        if(short_path[nd]) {
            for(auto i : previous[nd]) {
                if(!vis[i])
                    dijkstra.push(mp(-dist, i));
            }
        }
        for(auto i : edges[nd]) {
            if(!vis[i.fi]) {
                dijkstra.push(mp(-(dist + i.se), i.fi));
            }
        }
    }
    dijkstra.push(mp(0, u));
    while(dijkstra.size() > 0) {
        ll dist = -dijkstra.top().fi, nd = dijkstra.top().se;
        dijkstra.pop();
        if(nd == v) {
            res = min(res, dist);
            break;
        }
        else if(vis[nd])
            continue;
        vis[nd] = 1;
        if(short_path[nd]) {
            for(auto i : previous[nd]) {
                if(!vis[i])
                    dijkstra.push(mp(-dist, i));
            }
        }
        for(auto i : edges[nd]) {
            if(!vis[i.fi]) {
                dijkstra.push(mp(-(dist + i.se), i.fi));
            }
        }
    }
    cout << res << endl;
    return 0;
}