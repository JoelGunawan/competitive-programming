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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    pair<int, int> c[n];
    for(int i = 0; i < n; ++i)
        c[i] = {a[i], b[i]};
    sort(c, c + n);
    disjoint_set dsu;
    vector<int> d[31];
    for(int i = 0; i < n; ++i) {
        // find msb
        int msb;
        for(int j = 30; j >= 0; --j) {
            if((1 << j) & c[i].fi) {
                msb = j;
                break;
            }
        }
        for(int j = msb - 1; j >= 0; --j) {
            if(!((1 << j) & c[i].fi) && d[j].size()) {
                for(auto k : d[j])
                    dsu.merge(i, k);
                d[j].clear();
                d[j].pb(dsu.find_head(i));
            }
        }
        d[msb].pb(dsu.find_head(i));
    }
    ll res[n];
    memset(res, 0, sizeof(res));
    for(int i = 0; i < n; ++i) {
        res[dsu.find_head(i)] += c[i].se;
    }
    ll out[n];
    set<pair<pair<int, int>, int>> e;
    for(int i = 0; i < n; ++i)
        e.ins(mp(mp(a[i], b[i]), i));
    for(int i = 0; i < n; ++i) {
        out[(*e.lower_bound(mp(c[i], 0))).se] = res[dsu.find_head(i)];
        e.erase(e.lower_bound(mp(c[i], 0)));
    }
    for(int i = 0; i < n; ++i)
        cout << out[i] << endl;
    return 0;
}