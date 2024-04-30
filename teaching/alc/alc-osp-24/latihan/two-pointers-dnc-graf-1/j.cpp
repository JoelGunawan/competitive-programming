#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> rel[n + 1], jalan[n + 1];
    bool terhubung_rel[n + 1][n + 1];
    memset(terhubung_rel, 0, sizeof(terhubung_rel));
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        rel[u].push_back(v);
        rel[v].push_back(u);
        terhubung_rel[u][v] = true;
        terhubung_rel[v][u] = true;
    }
    // contoh (3, 1) tidak perlu di cek
    // karena waktu cek 1, kita sudah pasti memeriksa yang (1, 3)
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            if(!terhubung_rel[i][j]) {
                jalan[i].push_back(j);
                jalan[j].push_back(i);
            }
        }
    }

    // jalan terpendek utk rel dan jalan terpendek utk jalan -> bfs
    // mau bfs utk rel dan jalan
    // pair.first -> node
    // pair.second -> jarak
    queue<pair<int, int>> bfs;
    int jarak_rel[n + 1], jarak_bis[n + 1];
    // bool cek_rel[n + 1], cek_bis[n + 1]; bisa pakai ini kalo bingung
    // memset: bisa digunakan untuk set ke 0 / -1 di array integer
    memset(jarak_rel, -1, sizeof(jarak_rel));
    memset(jarak_bis, -1, sizeof(jarak_bis));
    // bfs jarak bis
    bfs.push(make_pair(1, 0));
    while(bfs.size()) {
        int node = bfs.front().first, jarak = bfs.front().second;
        bfs.pop();
        if(jarak_bis[node] != -1) {
            // sudah diproses
            continue;
        }
        jarak_bis[node] = jarak;
        for(int i = 0; i < jalan[node].size(); ++i) {
            if(jarak_bis[jalan[node][i]] == -1)
                bfs.push(make_pair(jalan[node][i], jarak + 1));
        }
    }
    // bfs jarak rel
    bfs.push(make_pair(1, 0));
    while(bfs.size()) {
        int node = bfs.front().first, jarak = bfs.front().second;
        bfs.pop();
        if(jarak_rel[node] != -1) {
            // sudah diproses
            continue;
        }
        jarak_rel[node] = jarak;
        for(int i = 0; i < rel[node].size(); ++i) {
            if(jarak_rel[rel[node][i]] == -1)
                bfs.push(make_pair(rel[node][i], jarak + 1));
        }
    }
    if(jarak_rel[n] == -1 || jarak_bis[n] == -1) {
        // gabisa dari 1 ke n (utk salah satunya)
        cout << -1 << endl; // diminta di soal
    }
    else {
        cout << max(jarak_rel[n], jarak_bis[n]) << endl;
    }
}