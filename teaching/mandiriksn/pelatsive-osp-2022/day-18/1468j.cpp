#include <bits/stdc++.h>
using namespace std;
const int lim = 2e5 + 5;
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
        }
        return x != y;
    }
};
disjoint_set dsu;
void tc() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        dsu.head[i] = -1;
        dsu.size[i] = 1;
    }
    // first -> speed limit
    // second.first -> node1
    // second.second -> node2
    pair<int, pair<int, int>> edges[m];
    for(int i = 0; i < m; ++i)
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    sort(edges, edges + m);
    int max_w = 0;
    for(int i = 0; i < m; ++i) {
        if(edges[i].first > k)
            break;
        else
            dsu.merge(edges[i].second.first, edges[i].second.second), max_w = edges[i].first;
    }
    int min_w = 2e9;
    for(int i = 0; i < m; ++i) {
        if(edges[i].first > k) {
            min_w = edges[i].first;
            break;
        }
    }
    // kalo dsu itu sudah connected 
    if(dsu.size[dsu.find_head(1)] == n) {
        cout << min(k - max_w, min_w - k) << endl;
        return;
    }
    long long result = 0;
    for(int i = 0; i < m; ++i) {
        if(dsu.merge(edges[i].second.first, edges[i].second.second))
            result += edges[i].first - k;
    }
    cout << result << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--)
        tc();
}