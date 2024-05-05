#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ll long long
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    // fi -> node
    // se -> weight
    vector<pair<int, int>> edges[n + 5];
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(mp(v, w));
        //edges[v].push_back(u);
    }
    // mau jarak paling kecil
    // pair.first -> jarak
    // pair.second -> node
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    // q.top() -> akses yang paling kecil/besar
    // q.pop() -> keluarkan yang di paling kecil/besar
    // q.push(x) -> masukkan elemen
    // q.size() -> banyak elemen
    q.push(mp(0, 1));
    bool vis[n + 5];
    memset(vis, 0, sizeof(vis));
    ll ans[n + 5];
    while(q.size()) {
        ll dist = q.top().fi; 
        int nd = q.top().se;
        q.pop();
        if(vis[nd])
            continue;
        vis[nd] = 1;
        ans[nd] = dist;
        for(auto i : edges[nd]) {
            if(!vis[i.fi])
                q.push(mp(dist + i.se, i.fi));
        }
    }
    for(int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}