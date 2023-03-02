#include <bits/stdc++.h>
using namespace std;
const int lim = 2e5 + 5;
struct dsu {
    int head[lim], size[lim];
    dsu() {
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
            size[x] += size[y];
            head[y] = x;
        }
        return x != y;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    pair<int, pair<int, int>> a[m + 1];
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = make_pair(w, make_pair(u, v));
    }
    dsu dsu1;
    sort(a + 1, a + m + 1);
    int res = 0;
    for(int i = 1; i <= m; ++i) {
        if(dsu1.find_head(a[i].second.first) != dsu1.find_head(a[i].second.second)) {
            res += a[i].first;
            dsu1.merge(a[i].second.first, a[i].second.second);
        }
    }
    cout << res << endl;
}