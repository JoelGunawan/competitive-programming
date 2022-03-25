#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert
using namespace std;
vector<pair<int, ll>> edges[5005];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // no tickets sold -> find minimum path in directed graph (use some form of dp)
    // k == 1 -> find minimum distance to the voting city from each city
    // the we need to find different configurations for 5 maximums
    // do a bitmask dp, where in each node we save 2 states, minimum to node x and the mask of tickets we use
    // transition might be quite slow
    // do dfs for each node
    // check minimum distance to other nodes
    // do dijkstra for each node
    // time complexity -> 3^5*q*(n+e)log(n+e)
    // per query kita dijkstra dp bitmask ke tiap node lain
    int n, e, k;
    cin >> n >> e >> k;
    int t[k];
    set<pair<ll, pair<int, int>>> dijkstra;
    for(int i = 0; i < k; ++i)
        cin >> t[i], dijkstra.ins(mp(0, mp(t[i], 0)));
    for(int i = 0; i < e; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        edges[v].pb(mp(u, c));
    }
    // create for each node the minimum distance using segment trees
    // determine which node we should process first by doing minimum query on segment tree and getting the index
    int q;
    ll min_dist[n][1 << 5];
    memset(min_dist, -1, sizeof(min_dist));
    bool vis[n][1 << 5];
    memset(vis, 0, sizeof(vis));
    // do multi source multi state dijkstra
    // sorted by lowest dist in set
    while(dijkstra.size()) {
        ll dist = (*dijkstra.begin()).fi;
        int nd = (*dijkstra.begin()).se.fi, mask = (*dijkstra.begin()).se.se;
        //cout << nd << " " << mask << " " << dist << endl;
        dijkstra.erase(dijkstra.begin());
        if(vis[nd][mask])
            continue;
        min_dist[nd][mask] = dist;
        vis[nd][mask] = 1;
        for(pair<int, ll> i : edges[nd]) {
            if(!vis[i.fi][mask])
                dijkstra.ins(mp(dist + i.se, mp(i.fi, mask)));
            for(int j = 0; j < 5; ++j) {
                if(!((1 << j) & mask)) {
                    if(!vis[i.fi][mask | (1 << j)])
                        dijkstra.ins(mp(dist + i.se / 10ll * (10 - j - 1), mp(i.fi, mask | (1 << j))));
                }
            }
        }
    }
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int s, p1, p2, p3, p4, p5;
        cin >> s;
        int p[5];
        for(int j = 0; j < 5; ++j)
            cin >> p[j];
        ll ans = 1e18;
        for(int j = 0; j < 1 << 5; ++j) {
            if(min_dist[s][j] != -1) {
                bool valid = 1;
                ll cost = 0;
                for(int k = 0; k < 5; ++k) {
                    if((1 << k) & j) {
                        if(p[k] == -1)
                            valid = 0;
                        else
                            cost += p[k];
                    }
                }
                //cout << j << " " << min_dist[s][j] << " " << cost << endl;
                if(valid)
                    ans = min(ans, min_dist[s][j] + cost);
            }
        }
        if(ans == 1e18)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}
