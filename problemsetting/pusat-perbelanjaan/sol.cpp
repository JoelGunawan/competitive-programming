#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    int a[k];
    for(int i = 0; i < k; ++i)
        cin >> a[i];
    priority_queue<pair<ll, pair<int, int>>> dj;
    for(int i = 0; i < k; ++i)
        dj.push(mp(0, mp(a[i], 0)));
    vector<pair<int, int>> edges[n + 1];
    for(int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        edges[u].pb(mp(v, t));
        edges[v].pb(mp(u, t));
    }
    ll dist[n + 1], dp[n + 1];
    memset(dp, 0, sizeof(dp));
    memset(dist, -1, sizeof(dist));
    dp[0] = 1;
    pair<int, int> queries[q];
    for(int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        queries[i] = mp(x, i);
    }
    sort(queries, queries + q);
    int ans[q];
    int q_idx = 0;
    ll total = 0;
    while(!dj.empty()) {
        ll cur = -dj.top().fi; int nd = dj.top().se.fi, pr = dj.top().se.se;
        while(q_idx < q && queries[q_idx].fi < cur)
            ans[queries[q_idx].se] = total, ++q_idx;
        dj.pop();
        if(dist[nd] < cur && dist[nd] != -1)
            continue;
        dist[nd] = cur;
        if(cur != 0)
            total += dp[pr];
        dp[nd] += dp[pr];
        if(total >= mod)
            total -= mod;
        if(dp[nd] >= mod)
            dp[nd] -= mod;
        for(auto i : edges[nd]) {
            if(dist[i.fi] == -1 || dist[i.fi] == cur + i.se)
                dj.push(mp(-(cur + i.se), mp(i.fi, nd)));
        }
    }
    while(q_idx < q)
        ans[queries[q_idx].se] = total, ++q_idx;
    for(int i = 0; i < q; ++i)
        cout << ans[i] << " ";
    cout << endl;
}