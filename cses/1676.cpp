// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
const int lim = 1e5 + 5;
struct disjoint_set {
    int h[lim], sz[lim];
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
            h[y] = x;
            sz[x] += sz[y];
        }
        return x != y;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int cc = n, mx = 1;
    disjoint_set dsu;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        if(dsu.merge(u, v)) {
            --cc, mx = max(mx, dsu.sz[dsu.fh(u)]);
        }
        cout << cc << " " << mx << endl;
    }
    return 0;
}