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
const int lim = 1e5 + 5;
struct disjoint_set {
    int h[lim], sz[lim], l[lim], r[lim];
    disjoint_set() {
        fill(sz, sz + lim, 1);
        memset(h, -1, sizeof(h));
        for(int i = 0; i < lim; ++i)
            l[i] = r[i] = i;
    }
    int fh(int nd) {
        while(h[nd] != -1)
            nd = h[nd];
        return nd;
    }
    bool merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y];
            h[y] = x;
            l[x] = min(l[x], l[y]);
            r[x] = max(r[x], r[y]);
        }
        return x != y;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    disjoint_set dsu;
    pair<int, int> p[n];
    for(int i = 0; i < n; ++i)
        cin >> p[i].se;
    for(int i = 0; i < n; ++i)
        cin >> p[i].fi;
    sort(p, p + n);
    reverse(p, p + n);
    ll res = 0;
    bool used[lim];
    memset(used, 0, sizeof(used));
    for(auto i : p) {
        int cur = dsu.l[dsu.fh(i.se)];
        //cout << cur << endl;
        while(dsu.l[dsu.fh(i.se)] != 1 && used[cur]) {
            dsu.merge(dsu.l[dsu.fh(i.se)] - 1, cur);
            cur = dsu.l[dsu.fh(i.se)];
        }
        //cout << cur << endl;
        if(used[cur])   
            continue;
        //cout << i.fi << " " << i.se << endl;
        used[cur] = 1;
        res += i.fi;
    }
    cout << res << endl;
    return 0;
}