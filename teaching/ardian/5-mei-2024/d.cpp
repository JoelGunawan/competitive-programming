#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> edges[n + 5];
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        //edges[v].push_back(u);
    }
    // pair.first -> node
    // pair.second -> jarak
    queue<pair<int, int>> q;
    // q.front() -> akses yang paling depan
    // q.pop() -> keluarkan yang di paling depan
    // q.push(x) -> masukkan elemen di belakang antrian
    // q.size() -> banyak elemen
    q.push(mp(1, 0));
    bool vis[n + 5];
    memset(vis, 0, sizeof(vis));
    while(q.size()) {
        int nd = q.front().fi, dist = q.front().se;
        q.pop();
        if(vis[nd])
            continue;
        vis[nd] = 1;
        for(auto i : edges[nd]) {
            q.push(mp(i, dist + 1));
        }
        cout << "DEBUG " << nd << " " << dist << endl;
    }
}