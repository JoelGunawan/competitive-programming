// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<bool> vis[n + 1];
    vector<int> id[n + 1];
    vector<ll> dist[n + 1];
    // fi -> id
    // se.fi.fi -> node
    // se.fi.se -> index id targetnya
    // se.se -> jarak
    vector<pair<int, pair<pair<int, int>, int>>> edges[n + 1];
    for(int i = 1; i <= m; ++i) {
        int u, v, p, t;
        cin >> u >> v >> p >> t;
        edges[u].push_back(mp(p, mp(mp(v, 0), t)));
        edges[v].pb(mp(p, mp(mp(u, 0), t)));
        id[u].push_back(p);
        id[v].push_back(p);
    }
    // id di sort
    // maintain id spy unique
    for(int i = 1; i <= n; ++i) {
        sort(id[i].begin(), id[i].end());
        sort(edges[i].begin(), edges[i].end());
    }
    for(int i = 1; i <= n; ++i) {
        vis[i].resize(id[i].size());
        dist[i].resize(id[i].size());
        fill(vis[i].begin(), vis[i].end(), 0);
        fill(dist[i].begin(), dist[i].end(), -1);
    }
    for(int i = 1; i <= n; ++i) {
        for(auto &j : edges[i]) {
            // assign index id target
            int cur_id = j.fi, target_nd = j.se.fi.fi;
            int target_idx = lower_bound(id[target_nd].begin(), id[target_nd].end(), cur_id) - id[target_nd].begin();
            j.se.fi.se = target_idx;
        }
    }
    // fractal search
    // fi -> dist
    // se.fi -> node
    // se.se -> index
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
    for(int i = 0; i < edges[1].size(); ++i) {
        pq.push(mp(edges[1][i].fi - 1, mp(1, i)));
    }
    while(pq.size()) {
        ll d = pq.top().fi; int nd = pq.top().se.fi, idx = pq.top().se.se;
        //cout << d << endl;
        //cout << nd << " " << idx << " " << id[nd][idx] << " " << d << endl;
        pq.pop();
        if(vis[nd][idx])
            continue;
        vis[nd][idx] = 1;
        dist[nd][idx] = d;
        // transisi ke atas bawah
        // ke bawah idx > 0
        if(idx > 0 && !vis[nd][idx - 1]) {
            pq.push(mp(d + id[nd][idx] - id[nd][idx - 1], mp(nd, idx - 1)));
        }
        // transisi ke atas
        // idx < id[nd].size() - 1
        if(idx < id[nd].size() - 1 && !vis[nd][idx + 1]) {
            pq.push(mp(d + id[nd][idx + 1] - id[nd][idx], mp(nd, idx + 1)));
        }
        // perlu consider edge yang edges[nd][idx] aja
        if(!vis[edges[nd][idx].se.fi.fi][edges[nd][idx].se.fi.se]) {
            pq.push(mp(d + edges[nd][idx].se.se, mp(edges[nd][idx].se.fi.fi, edges[nd][idx].se.fi.se)));
        }
    }
    ll ret = 1e18;
    for(int i = 0; i < edges[n].size(); ++i) {
        ret = min(ret, dist[n][i] + id[n][i] - 1);
    }
    cout << ret << endl;
    return 0;
}