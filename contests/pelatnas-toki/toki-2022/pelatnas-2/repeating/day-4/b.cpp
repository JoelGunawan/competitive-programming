// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
#define ll long long
#define lb lower_bound
#define mp make_pair
#define ins insert
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
set<pair<int, pair<int, int>>> active_edges;
ll res = 0;
struct dsu {
    int head[100001], value[100001], size[100001];
    dsu() {
        fill(size, size + 100001, 1);
        memset(head, -1, sizeof(head));
    }
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    void merge(int x, int y) {
        x = find_head(x), y = find_head(y);
        //cout << x << " " << y << endl;
        // merge edges
        // edge merge tricky :weary:
        // harus ubah index 
        // x is bigger
        if(size[x] < size[y])
            swap(x, y);
        size[x] += size[y], head[y] = x;
        res += value[x] + value[y];
        value[x] = max(value[x], value[y]);
    }
};
int main() {
    // use dsu on tree
    // greedy minimum max
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n + 1];
    dsu dsu;
    for(int i = 1; i <= n; ++i)
        cin >> a[i], dsu.value[i] = a[i];
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        active_edges.ins(mp(max(a[u], a[v]), mp(min(u, v), max(u, v))));
    }
    while(active_edges.size() > 0) {
        dsu.merge((*active_edges.begin()).se.fi, (*active_edges.begin()).se.se);
        active_edges.erase(active_edges.begin());
    }
    cout << res << endl;
    return 0;
}