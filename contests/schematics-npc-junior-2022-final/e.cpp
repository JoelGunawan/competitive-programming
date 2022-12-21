#include <bits/stdc++.h>
using namespace std;
const int lim = 2e5 + 5;
pair<long long, int> ans = {0, 0};
struct disjoint_set {
    int head[lim], size[lim], minimum[lim];
    long long res[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
        memset(res, 0, sizeof(res));
        fill(minimum, minimum + lim, 1e9);
    }
    int fh(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            size[x] += size[y], head[y] = x, res[x] += res[y], minimum[x] = min(minimum[x], minimum[y]);
            ans = max(ans, {res[x], -minimum[x]});
        }
        return x != y;
    }
};
int main() {
    // sort query from large to small
    // do dsu to find cc with largest value
    // then with smallest minimum   
    int n, m;
    cin >> n >> m;
    int val[n];
    for(int i = 0; i < n; ++i)
        cin >> val[i];
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, make_pair(u, v)});
    }
    int h;
    cin >> h;
    pair<int, int> q[h];
    for(int i = 0; i < h; ++i) {
        int x;
        cin >> x;
        q[i] = {x, i};
    }
    sort(q, q + h);
    reverse(q, q + h);
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    disjoint_set dsu;
    for(int i = 0; i < n; ++i) {
        dsu.res[i] = val[i];
        dsu.minimum[i] = i;
        ans = max(ans, {dsu.res[i], -dsu.minimum[i]});
    }
    int out[h];
    int idx = 0;
    for(int i = 0; i < m; ++i) {
        while(idx < h && q[idx].first > edges[i].first) {
            out[q[idx].second] = -ans.second;
            ++idx;
        }
        dsu.merge(edges[i].second.first, edges[i].second.second);
    }
    while(idx < h) {
        out[q[idx].second] = -ans.second;
        ++idx;
    }
    for(int i = 0; i < h; ++i)
        cout << out[i] << '\n';
}