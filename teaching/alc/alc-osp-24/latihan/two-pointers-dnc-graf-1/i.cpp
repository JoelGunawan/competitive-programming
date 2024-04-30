#include <bits/stdc++.h>
using namespace std;
vector<int> edges[100005], inv[100005];
bool vis1[100005], vis2[100005];
// dfs di graf yg tidak terbalik
void dfs1(int nd) {
    vis1[nd] = 1;
    for(int i = 0; i < edges[nd].size(); ++i) {
        if(!vis1[edges[nd][i]])
            dfs1(edges[nd][i]);
    }
}

// dfs di graf yg terbalik
void dfs2(int nd) {
    vis2[nd] = 1;
    for(int i = 0; i < inv[nd].size(); ++i) {
        if(!vis2[inv[nd][i]])
            dfs2(inv[nd][i]);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        inv[v].push_back(u);
    }
    dfs1(1);
    dfs2(1);
    for(int i = 1; i <= n; ++i) {
        // dfs yg searah tdk bisa dikunjungi
        if(!vis1[i]) {
            // tidak ada jalan dari 1 ke i
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return 0;
        }
    }
    for(int i = 1; i <= n; ++i) {
        // dfs yg kebalik tdk bisa dikunjungi
        if(!vis2[i]) {
            // tidak ada jalan dari i ke 1
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return 0; 
        }
    }
    cout << "YES" << endl;
}