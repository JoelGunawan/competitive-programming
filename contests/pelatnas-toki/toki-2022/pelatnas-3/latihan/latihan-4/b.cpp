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
const int lim = 1e5 + 5;
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
            head[y] = x, size[x] += size[y];
        }
        return x != y;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    pair<pair<int, bool>, pair<int, int>> a[p + q];
    ll total = 0;
    for(int i = 0; i < p; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = mp(mp(z, 0), mp(x, y));
        total += 1ll * z * n;
    }
    for(int i = 0; i < q; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        a[i + p] = mp(mp(z, 1), mp(x, y));
        total += 1ll * z * m;
    }
    sort(a, a + p + q);
    int acnt = 0, bcnt = 0;
    dsu adsu, bdsu;
    ll res = 0;
    for(int i = 0; i < p + q; ++i) {
        if(a[i].fi.se) {
            if(adsu.merge(a[i].se.fi, a[i].se.se)) {
                res += 1ll * a[i].fi.fi * (m - bcnt);
                ++acnt;
            }
        }
        else {
            if(bdsu.merge(a[i].se.fi, a[i].se.se)) {
                res += 1ll * a[i].fi.fi * (n - acnt);
                ++bcnt;
            }
        }
    }
    cout << total - res << endl;
    return 0;
}