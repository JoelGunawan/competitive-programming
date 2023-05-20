#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int lim = 1e5 + 5;
int low[lim], disc[lim], ti;
vector<int> edges[lim];
vector<pair<int, int>> bridge;
void dfs(int nd = 1, int par = 0) {
    low[nd] = disc[nd] = ti++;
    for(auto i : edges[nd]) {
        // side edge pasti boleh
        if(i == par)
            continue;
        //cout << "EDGE " << nd << " " << i << endl;
        if(disc[i] == -1) {
            dfs(i, nd);
            low[nd] = min({low[nd], low[i]});
            if(low[i] > disc[nd]) {
                bridge.push_back({min(nd, i), max(nd, i)});
            }
        }
        else {
            low[nd] = min({low[nd], disc[i]});
        }
    }
    //cout << nd << " " << low[nd] << " " << disc[nd] << endl;
}
struct disjoint_set {
    int h[lim], sz[lim];
    vector<int> edges[lim];
    disjoint_set() {
        memset(h, -1, sizeof(h));
        fill(sz, sz + lim, 1);
    }
    int fh(int nd) {
        return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
    }
    void merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y];
            h[y] = x;
            if(edges[x].size() < edges[y].size())
                swap(edges[x], edges[y]);
            for(auto i : edges[y])
                edges[x].push_back(i);
        }
    }
};
int dist[lim];
bool vis[lim];
void dfs2(int nd) {
    vis[nd] = 1;
    //cout << nd << " " << dist[nd] << endl;
    for(auto i : edges[nd]) {
        //cout << nd << " " << i << " " << vis[i] << endl;
        if(!vis[i]) {
            dist[i] = dist[nd] + 1;
            dfs2(i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        ti = 0;
        // buat bridge tree, terus nanti cari diameternya
        // hubungin kedua diameternya
        // ez kannnnnn
        vector<pair<int, int>> adj;
        for(int i = 1; i <= n; ++i) {
            edges[i].clear();
        }
        memset(low, -1, sizeof(low));
        memset(disc, -1, sizeof(disc));
        bridge.clear();
        for(int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
            adj.push_back({min(u, v), max(u, v)});
        }
        dfs(1, 0);
        sort(bridge.begin(), bridge.end());
        // get bridges
        disjoint_set dsu;
        for(int i = 1; i <= n; ++i) {
            edges[i].clear();
        }
        for(auto i : bridge) {
            dsu.edges[i.first].push_back(i.second);
            dsu.edges[i.second].push_back(i.first);
            //cout << "BRIDGE INPUT " << i.first << " " << i.second << endl;
        }
        for(auto i : adj) {
            if(!binary_search(bridge.begin(), bridge.end(), i)) {
                //cout << "MERGE " << i.first << " " << i.second << endl;
                dsu.merge(i.first, i.second);
            }
        }
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; ++i) {
            if(!vis[dsu.fh(i)]) {
                for(auto j : dsu.edges[dsu.fh(i)]) {
                    //cout << "OUTPUT " << dsu.fh(i) << " " << dsu.fh(j) << endl;
                    edges[dsu.fh(j)].push_back(dsu.fh(i));
                }
                vis[dsu.fh(i)] = 1;
            }
        }
        memset(vis, 0, sizeof(vis));
        memset(dist, 0, sizeof(dist));
        dfs2(dsu.fh(1));
        pair<int, int> mx = {-1e9, -1e9};
        for(int i = 1; i <= n; ++i) {
            mx = max(mx, {dist[i], i});
        }
        memset(vis, 0, sizeof(vis));
        memset(dist, 0, sizeof(dist));
        //cout << "SECOND" << endl;
        dfs2(mx.second);
        mx = {-1e9, -1e9};
        for(int i = 1; i <= n; ++i) {
            mx = max(mx, {dist[i], i});
        }
        cout << (int)bridge.size() - mx.first << endl;
        //cout << "BRIDGES" << endl;
        //for(auto i : bridge) {
        //    cout << i.first << " " << i.second << endl;
        //}
        // merge yg 1 cc
        // nanti buat dfs 2 kali di bridge nya
    }
}