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
int dep_cnt[lim];
struct disjoint_set {
    int head[lim], size[lim], ans[lim];
    map<int, int> dep[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
        memset(ans, 0, sizeof(ans));
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
            size[x] += size[y], head[y] = x;
            for(auto i : dep[y]) {
                if(dep[x][i.fi]) {
                    dep[x][i.fi] += i.se;
                    if(dep[x][i.fi] == dep_cnt[i.fi])
                        --ans[x];
                }
                else {
                    dep[x][i.fi] += i.se;
                    if(dep[x][i.fi] != dep_cnt[i.fi])
                        ++ans[x];
                }
            }
        }
        return x != y;
    }

};
vector<int> edges[lim], dep_nd[lim], ans;
bool vis[lim];
int k, depth[lim];
disjoint_set dsu;
void dfs(int nd) {
    vis[nd] = 1;
    for(auto i : dep_nd[nd]) {
        ++dsu.dep[nd][i];
        if(dep_cnt[i] != 1)
            ++dsu.ans[nd];
    }
    for(auto i : edges[nd]) {
        if(!vis[i])
            depth[i] = depth[nd] + 1, dfs(i), dsu.merge(nd, i);
    }
    //cout << "ND " << nd << " " << dsu.ans[dsu.fh(nd)] << endl;
    if(dsu.ans[dsu.fh(nd)] >= k)
        ans.pb(nd);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // sol:
    // use subtree count
    // in each node, a par edge is used if not all the neighborhoods are in the subtree
    // use DSU On Tree, maintaining count of elements and amount of active
    // ez
    int n, m;
    cin >> n >> m >> k;
    vector<pair<int, int>> adj;
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
        adj.pb(mp(u, v));
    }
    for(int i = 1; i <= m; ++i) {
        int s;
        cin >> s;
        dep_cnt[i] = s;
        while(s--) {
            int x;
            cin >> x;
            dep_nd[x].pb(i);
        }
    }
    dfs(1);
    // yang child di fi
    // se jadi number
    for(int i = 0; i < adj.size(); ++i) {
        if(depth[adj[i].fi] < depth[adj[i].se])
            swap(adj[i].fi, adj[i].se);
        adj[i].se = i + 1;
    }
    sort(adj.begin(), adj.end());
    vector<int> res;
    for(auto i : ans)
        res.pb((*lower_bound(adj.begin(), adj.end(), mp(i, 0))).se);
    //cout << endl;
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for(auto i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}