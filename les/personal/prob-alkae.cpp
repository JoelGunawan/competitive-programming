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
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int lim = 1e4 + 5;
struct disjoint_set {
    int sz[lim], h[lim];
    disjoint_set() {
        fill(sz, sz + lim, 1);
        memset(h, -1, sizeof(h));
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
    int k[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> k[i];
    pair<pair<int, int>, int> a[m];
    for(int i = 0; i < m; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        a[i] = mp(mp(min(u, v), max(u, v)), x);
    }
    sort(a, a + m);
    disjoint_set dsu;
    for(auto i : a) {
        dsu.merge(i.fi.fi, i.fi.se);
    }
    multiset<int> dkt[n + 1], pd[n + 1];
    for(int i = 1; i <= n; ++i) {
        int head = dsu.fh(i);
        //cout << i << " " << head << endl;
        pd[head].ins(k[i]);
    }
    for(int i = 0; i < m; ++i) {
        int x = dsu.fh(a[i].fi.fi);
        dkt[x].ins(a[i].se);
    }
    int q;
    cin >> q;
    while(q--) {
        char op;
        cin >> op;
        if(op == '?') {
            int t;
            cin >> t;
            if(t == 1) {
                int x;
                cin >> x;
                int tmp = dsu.fh(x);
                if(dkt[tmp].empty())
                    cout << 0 << endl;
                else
                    cout << (*dkt[tmp].begin()) << endl;
            }
            else {
                int a, b;
                cin >> a >> b;
                a = dsu.fh(a), b = dsu.fh(b);
                if(a == b)
                    cout << 0 << endl;
                else {
                    cout << (*--pd[a].end()) + (*--pd[b].end()) << endl;
                }
            }
        }
        else {
            int t;
            cin >> t;
            if(t == 1) {
                int a, x;
                cin >> a >> x;
                int tmp = dsu.fh(a);
                //cout << a << " " << tmp << " " << x << " " << k[a] << endl;
                pd[tmp].erase(pd[tmp].lb(k[a]));
                k[a] = x;
                pd[tmp].ins(k[a]);
            }
            else {
                int x, y, w;
                cin >> x >> y >> w;
                if(x > y)
                    swap(x, y);
                int cc = dsu.fh(x);
                int idx = lower_bound(a, a + m, mp(mp(x, y), 0)) - a;
                //cout << x << " " << y << " " << w << " " << cc << endl;
                //cout << dkt[cc].size() << " " << *dkt[cc].lb(a[idx].se) << endl;
                dkt[cc].erase(dkt[cc].lb(a[idx].se));
                // mis {3 3 3}
                // ms.erase(3)
                // isi jadi {}
                a[idx].se = w;
                dkt[cc].ins(a[idx].se);
            }
        }
    }
    return 0;
}