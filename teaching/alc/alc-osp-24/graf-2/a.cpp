#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    // pertama -> node, kedua -> bobot
    vector<pair<int, int>> edges[n + 1];
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(make_pair(v, w)); // ada edge dr u -> v dengan bobot w
        edges[v].push_back(make_pair(u, w)); // ada edge dr v -> u dengan bobot w
    }
    // operasi utk kumpulan:
    // insert ke kumpulan
    // mau cari yg jaraknya paling kecil di kumpulan
    // keluarkan yg jaraknya paling kecil dr kumpulan
    // struktur data priority queue
    // pair.first -> jarak
    // pair.second -> node
    // priority queue -> prioritas dari paling besar
    // mau cari minimum -> jadikan negatif, supaya yang "maksimum" jadi "minimum"
    priority_queue<pair<long long, int>> pq;
    pq.push(make_pair(-0, 1));
    long long jarak_terpendek[n + 1];
    memset(jarak_terpendek, -1, sizeof(jarak_terpendek));
    while(pq.size()) {
        long long jarak = -pq.top().first;
        int node = pq.top().second;
        cout << "DEBUG " << node << " " << jarak << endl;
        pq.pop();
        if(jarak_terpendek[node] != -1)
            continue;
        jarak_terpendek[node] = jarak;
        for(int i = 0; i < edges[node].size(); ++i) {
            if(jarak_terpendek[edges[node][i].first] == -1) {
                // pertama -> -jarak
                // kedua -> node
                pq.push(make_pair(-(jarak + edges[node][i].second), edges[node][i].first));
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        cout << jarak_terpendek[i] << " ";
    }
    cout << endl;
}