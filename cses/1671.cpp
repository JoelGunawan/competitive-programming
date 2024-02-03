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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges[n + 1];
    for(int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].pb(mp(b, c));
    }
    // default: large to small
    // cara balik:
    // ini small to large
    // fi -> dist, se -> node
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push(mp(0, 1));
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    ll ans[n + 1];
    while(pq.size()) {
        ll dist = pq.top().fi; int nd = pq.top().se;
        pq.pop();
        if(vis[nd])
            continue;
        vis[nd] = 1;
        ans[nd] = dist;
        for(auto i : edges[nd]) {
            // i.fi -> node tujuan, i.se -> weight edgenya
            if(!vis[i.fi])
                pq.push(mp(dist + i.se, i.fi));
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}