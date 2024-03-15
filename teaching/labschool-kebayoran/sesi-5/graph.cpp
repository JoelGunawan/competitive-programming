// dijkstra
// kruskall (dsu)
// bfs
// dfs
#include <bits/stdc++.h>
using namespace std;
const int lim = 2e5 + 5;
bool vis[lim];
int subtree[lim];
vector<int> edges[lim];
// dfs subtree
int dfs(int nd) {
    vis[nd] = 1;
    subtree[nd] = 1;
    for(auto i : edges[nd])
        if(!vis[i])
            subtree[nd] += dfs(i);
    return subtree[nd];
}
struct disjoint_set {
    int head[lim], size[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
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
            size[x] += size[y], head[y] = x;
            // kode merging
        }
        return x != y;
    }
};
int main() {
    // bfs -> queue
    queue<int> q;
    bool vis[lim];
    q.push(1);
    while(!q.empty()) {
        int nd = q.front();
        q.pop();
        if(vis[nd])
            continue;
        // operasi hitungan
        for(auto i : edges[nd]) {
            if(!vis[i])
                q.push(i);
        }
    }
    priority_queue<pair<int, int>> dj;
    dj.push({0, 1});
    while(!dj.empty()) {
        int dist = -dj.top().first, nd = dj.top().second;
        q.pop();
        if(vis[nd])
            continue;
        // operasi hitungan
        for(auto i : edges[nd]) {
            if(!vis[i.first])
                dj.push({-(i.second + dist), i.first});
        }
    }
    // multisource dijkstra/bfs
    vector<pair<int, pair<int, int>>> adj;
    disjoint_set dsu;
    sort(adj.begin(), adj.end());
    for(auto i : adj) {
        if(dsu.merge())
    }
}