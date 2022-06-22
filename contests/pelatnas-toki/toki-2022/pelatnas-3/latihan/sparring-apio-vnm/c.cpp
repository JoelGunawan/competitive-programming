#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
// pakai DP CC?
// jika komponen (u, v) connected dengan edge di min span tree, maka semua edge yang menghubungkan antara (u, v) harus >= cur_edge
// pilihannya antara kita tambah semua edge lain agar kurang dri cur
// atau kita reduce edge kita sekarang
// yang pasti harus <= yang tidak ada di max span tree
// setelah edge yang tidak ada di keduanya udah non issue
// baru di cek cara paling optimal buat reduce/add
// ijin ke toilet
struct disjoint_set_edge {
    int head[(int)(1e3 + 5)], size[(int)(1e3 + 5)];
    vector<int> isi[(int)(1e3 + 5)];
    disjoint_set_edge() {
        memset(head, -1, sizeof(head));
        fill(size, size + (int)1e3 + 5, 1);
    }
    // merge semua edge, maintain weights aja
    // cari titik yang paling minimal untuk samakan
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int x, int y) {
        x = find_head(x), y = find_head(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            size[x] += size[y];
            head[y] = x;
            for(auto i : isi[y])
                isi[x].push_back(i);
        }
        return x != y;
    }
};
struct disjoint_set_node {
    int head[55], size[55];
    disjoint_set_node() {
        memset(head, -1, sizeof(head));
        fill(size, size + 55, 1);
    }
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int x, int y) {
        x = find_head(x), y = find_head(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            size[x] += size[y];
            head[y] = x;
        }
        return x != y;
    }
};
vector<pair<int, int>> edges[55];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int buang;
    cin >> buang;
    int n, m;
    cin >> n >> m;
    // go to median
    // for each common edge
    pair<pair<int, int>, int> adj[m + 1];
    disjoint_set_edge dsu_edge;
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[i] = {{u, v}, w};
        edges[u].push_back({v, i});
        edges[v].push_back({u, i});
        dsu_edge.isi[i].push_back(w);
    }
    int t[n], g[n];
    t[0] = 0, g[0] = 0;
    for(int i = 1; i <= n - 1; ++i)
        cin >> t[i];
    for(int j = 1; j <= n - 1; ++j)
        cin >> g[j];
    bool equal = 1;
    // find first difference
    sort(t, t + n);
    sort(g, g + n);
    for(int i = 0; i < n; ++i)
        equal &= t[i] == g[i];
    if(equal) {
        for(int i = 1; i <= n - 1; ++i) {
            disjoint_set_node dsu;
            for(int j = 1; j <= n - 1; ++j) {
                if(j != i)
                    dsu.merge(adj[t[j]].first.first, adj[t[j]].first.second);
            }
            for(int j = 1; j <= m; ++j)
                if(dsu.find_head(adj[j].first.first) != dsu.find_head(adj[j].first.second))
                    dsu_edge.merge(t[i], j);
        }
        bool vis[m + 1];
        memset(vis, 0, sizeof(vis));
        long long res = 0;
        for(int i = 1; i <= m; ++i) {
            if(!vis[dsu_edge.find_head(i)]) {
                vis[dsu_edge.find_head(i)] = 1;
                vector<int> &tmp = dsu_edge.isi[dsu_edge.find_head(i)];
                sort(tmp.begin(), tmp.end());
                int median;
                if(tmp.size() & 1)
                    median = tmp[tmp.size() / 2];   
                else 
                    median = (tmp[tmp.size() / 2 - 1] + tmp[tmp.size() / 2]) / 2;
                for(auto j : tmp)
                    res += abs(j - median);
            }
        }
        cout << res << endl;
        return 0;
    }
    multiset<int> common, fi;
    for(int i = 1; i <= n - 1; ++i) {
        fi.insert(t[i]);
    }
    for(int i = 1; i <= n - 1; ++i) {
        if(fi.find(g[i]) != fi.end())
            common.insert(g[i]);
    }
    int x, y, maxi = 0, mini = INT_MAX;
    for(int i = 1; i <= n - 1; ++i) {
        if(common.find(t[i]) == common.end())
            x = t[i];
        else
            maxi = max(maxi, adj[t[i]].second), mini = min(mini, adj[t[i]].second);
        if(common.find(g[i]) == common.end())
            y = g[i];
    }
    // max without min without
    // x <= maxi
    // y >= mini
    // x <= y
    long long result = 0;
    x = adj[x].second, y = adj[y].second;
    cout << max(0, x - (y - 1)) << endl;
    // ijin ke toilet
    return 0;
}