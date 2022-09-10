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
const int lim = 55;
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
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, pair<int, int>>> adj;
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj.pb(mp(mp(w, 0), mp(u, v)));
    }
    sort(adj.begin(), adj.end());
    for(int i = 0; i < m; ++i)
        adj[i].fi.se = i;
    int p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    // find configuration of spanning trees
    // all combination of spanning trees -> not a lot
    // start from 0, binary search a configuration is valid till when
    // fi -> boundary
    // se -> the configuration
    vector<pair<int, vector<int>>> configs;
    int last = 0;
    disjoint_set dsu;
    while(last < c) {
        dsu.reset();
        int l = last, r = c - 1, ans;
        vector<int> cur_conf;
        vector<pair<pair<int, int>, pair<int, int>>> tmp_adj = adj;
        for(auto &j : tmp_adj)
            j.fi.fi = abs(j.fi.fi - last);
        sort(tmp_adj.begin(), tmp_adj.end());
        dsu.reset();
        for(auto i : tmp_adj) {
            if(dsu.merge(i.se.fi, i.se.se)) {
                cur_conf.pb(i.fi.se);
            }
        }
        sort(cur_conf.begin(), cur_conf.end());
        while(l <= r) {
            int mid = (l + r) >> 1;
            tmp_adj = adj;
            for(auto &j : tmp_adj)
                j.fi.fi = abs(j.fi.fi - mid);
            sort(tmp_adj.begin(), tmp_adj.end());
            dsu.reset();
            vector<int> test_conf;
            for(auto i : tmp_adj) {
                if(dsu.merge(i.se.fi, i.se.se)) {
                    test_conf.pb(i.fi.se);
                }
            }
            sort(test_conf.begin(), test_conf.end());
            if(cur_conf != test_conf)
                r = mid - 1;
            else
                l = mid + 1, ans = mid;
        }
        configs.pb(mp(ans, cur_conf));
        last = ans + 1;
    }
    int q[p];
    for(int i = 0; i < p; ++i)
        cin >> q[i];
    // for each query, find range -> get sum using each edge -> O(50k)
    ll res = 0;
    for(int i = 0; i < p; ++i) {
        int idx = lower_bound(configs.begin(), configs.end(), mp(q[i], vector<int>())) - configs.begin();
        ll cur_res = 0;
        for(auto j : configs[idx].se) {
            cur_res += abs(adj[j].fi.fi - q[i]);
        } 
        res ^= cur_res;
    }
    int cur = (1ll * q[p - 1] * a + b) % c;
    for(int i = p; i < k; ++i) {
        int idx = lower_bound(configs.begin(), configs.end(), mp(cur, vector<int>())) - configs.begin();
        ll cur_res = 0;
        for(auto j : configs[idx].se) {
            cur_res += abs(adj[j].fi.fi - cur);
        } 
        res ^= cur_res;
        cur = (1ll * cur * a + b) % c;
    }
    cout << res << endl;
    return 0;
}