#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int lim = 1005;
struct disjoint_set {
    int h[lim], sz[lim];
    multiset<int> a[lim];
    disjoint_set() {
        memset(h, -1, sizeof(h));
        fill(sz, sz + lim, 1);
    }
    int fh(int nd) {
        return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
    }
    bool merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y];
            h[y] = x;
            // merge multiset
            for(auto i : a[y])
                a[x].insert(i);
        }
        return x != y;
    }
};
bool vis[lim];
int val[lim];
vector<int> edges[lim];
disjoint_set dsu;
void dfs(int nd) {
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            dfs(i);
            dsu.merge(nd, i);
        }
    }
    if(nd != 0 && edges[nd].size() == 1) {
        // merupakan leaf
        dsu.a[dsu.fh(nd)].insert(val[nd]);
    }
    else if(nd != 0 && dsu.a[dsu.fh(nd)].lower_bound(val[nd]) != dsu.a[dsu.fh(nd)].begin()) {
        // bukan leaf -> gnti yg di subtree sama valuenya (gnti yg paling kecil jadi sekarang (kalo sekarang lebih tinggi))
        dsu.a[dsu.fh(nd)].erase(dsu.a[dsu.fh(nd)].begin());
        dsu.a[dsu.fh(nd)].insert(val[nd]);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> val[i];
    for(int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(0);
    long long res = 0;
    for(auto i : dsu.a[dsu.fh(0)]) {
        res += i;
    }
    cout << res << endl;
}