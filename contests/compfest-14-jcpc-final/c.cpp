// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
const int lim = 2e3 + 5;
struct disjoint_set {
    int head[lim], size[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
    }
    void reset() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
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
            head[y] = x, size[x] += size[y];
        }
        return x != y;
    }
};
vector<int> edges[lim];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // optimal 
    int n, s, a;
    cin >> n >> s >> a;
    vector<pair<int, int>> adj;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj.pb(mp(u, v));
        edges[u].pb(v);
        edges[v].pb(u);
    }
    sort(adj.begin(), adj.end()); 
    ll ans = min(max(0ll + s, 1ll * a * n), max(1ll * s * n, 0ll + a));
    for(int i = 1; i <= n; ++i) {
        int merged = 0;
        for(int j = i; j <= n; ++j) {
            for(auto k : edges[j]) {
                if(k >= i && k <= j) {
                    ++merged;
                }
            }
            ans = min(ans, max(1ll * (n - merged) * a, 1ll * (j - i + 1) * s));
        }
    }
    cout << ans << endl;
    return 0;
}