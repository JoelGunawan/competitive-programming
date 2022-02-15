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
vector<pair<int, int>> edges[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].pb(mp(v, w));
        edges[v].pb(mp(u, w));
    }
    priority_queue<pair<ll, pair<int, int>>> pq;
    pq.push(mp(0, mp(1, 0)));
    ll res[n + 1];
    int prev[n + 1];
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    memset(res, -1, sizeof(res));
    memset(prev, -1, sizeof(prev));
    while(pq.size() > 0) {
        pair<ll, pair<int, int>> cur = pq.top();
        pq.pop();
        ll cur_dist = -cur.fi; int nd = cur.se.fi, prev_nd = cur.se.se;
        if(vis[nd])
            continue;
        vis[nd] = 1;
        prev[nd] = prev_nd;
        res[nd] = cur_dist;
        for(auto i : edges[nd]) {
            if(!vis[i.fi]) {
                pq.push(mp(-(cur_dist + i.se), mp(i.fi, nd)));
            }
        }
    }
    if(res[n] == -1)
        cout << -1 << endl;
    else {
        int cur = n;
        vector<int> tmp;
        while(cur >= 1)
            tmp.pb(cur), cur = prev[cur];
        reverse(tmp.begin(), tmp.end());
        for(auto i : tmp)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}