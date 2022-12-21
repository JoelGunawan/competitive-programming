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
const int lim = 155;
vector<pair<int, pair<int, int>>> edges[lim];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m, x;
    cin >> n >> m >> x;
    for(int i = 0; i < m; ++i) {
        int u, v, w, y;
        cin >> u >> v >> w >> y;
        edges[u].pb(mp(v, mp(w, y)));
        edges[v].pb(mp(u, mp(w, y)));
    }
    // 15*150*50
    // state -> dist[origin][cur][exec]
    // 1e5
    // transition -> O(m)
    // 500/1000
    set<int> og;
    int q;
    cin >> q;
    vector<pair<pair<int, int>, pair<int, int>>> query;
    for(int i = 0; i < q; ++i) {
        int a, b, p, e;
        cin >> a >> b >> p >> e;
        og.ins(a);
        query.pb(mp(mp(a, b), mp(p, e)));
    }
    // for each in og, put into origin
    ll ans[205][og.size()][n][x + 1];
    bool vis[205][og.size()][n][x + 1];
    memset(vis, 0, sizeof(vis));
    memset(ans, -1, sizeof(ans));
    // set all of them as origin points
    // fi.fi -> dist
    // fi.se -> depth
    // se.fi -> cur_node
    // se.se.fi -> og_node
    // se.se.se -> exec used
    priority_queue<pair<pair<ll, int>, pair<int, pair<int, int>>>> pq;
    auto it = og.begin();
    int og_num[n];
    for(int i = 0; i < og.size(); ++i) {
        pq.push(mp(mp(0, 0), mp(*it, mp(i, 0))));
        og_num[*it] = i;
        ++it;
    }
    while(pq.size()) {
        ll dist = -pq.top().fi.fi;
        int depth = pq.top().fi.se, nd = pq.top().se.fi, og = pq.top().se.se.fi, exec = pq.top().se.se.se;
        pq.pop();
        if(vis[depth][og][nd][exec])
            continue;
        vis[depth][og][nd][exec] = 1;
        ans[depth][og][nd][exec] = dist;
        if(depth == 200)
            continue;
        for(auto i : edges[nd]) {
            if(i.se.se) {
                if(exec + 1 <= x && !vis[depth + 1][og][i.fi][exec + 1])
                    pq.push(mp(mp(-(dist + i.se.fi), depth + 1), mp(i.fi, mp(og, exec + 1))));
            }
            else {
                if(!vis[depth + 1][og][i.fi][exec])
                    pq.push(mp(mp(-(dist + i.se.fi), depth + 1), mp(i.fi, mp(og, exec))));
            }
        }
    }
    for(auto i : query) {
        int a = i.fi.fi, b = i.fi.se, p = i.se.fi, e = i.se.se;
        cout << ans[p][og_num[a]][b][e] << endl;
    }
    return 0;
}