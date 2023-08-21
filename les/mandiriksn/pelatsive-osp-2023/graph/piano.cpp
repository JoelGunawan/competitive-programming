#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    // fi -> node
    // se -> weight edge
    vector<pair<int, int>> edges[n + 1];
    for(int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        edges[x].push_back(make_pair(y, z));
        edges[y].push_back(make_pair(x, z));
    }
    // priority_queue 
    // state pertama -> wajib dist
    // semakin ke depan, yg harus urut, tergantung prioritas urutan
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, a));
    while(pq.size()) {
        int dist = pq.top().first, nd = pq.top().second;
        pq.pop();
        if(vis[nd])
            continue;
        vis[nd] = 1;
        if(nd == b) {
            cout << dist << endl;
            break;
        }
        for(auto i : edges[nd]) {
            if(!vis[i.first])
                pq.push(make_pair(dist + i.second, i.first));
        }
    }
}