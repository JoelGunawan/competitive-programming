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
const int lim = 2e5 + 5;
vector<int> edges[lim];
bool vis[lim];
int par[18][lim], depth[lim];
void dfs(int nd) {
    vis[nd] = 1;
    int tmp = 0, tmp2 = par[0][nd];
    while(tmp2 != 0) {
        par[tmp][nd] = tmp2;
        tmp2 = par[tmp][tmp2], ++tmp;
    }
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            depth[i] = depth[nd] + 1;
            par[0][i] = nd;
            dfs(i);
        }
    }
}
int lca(int x, int y) {
    if(depth[x] > depth[y])
        swap(x, y);
    for(int i = 17; i >= 0; --i) {
        if(depth[y] - depth[x] >= (1 << i)) {
            y = par[i][y];
            //cout << "DEPTH " <<depth[x] << " " << depth[y] << endl;
        }
    }
    //cout << "LCA " << x << " " << y << endl;
    if(x == y)
        return x;
    for(int i = 17; i >= 0; --i) {
        if(par[i][x] != par[i][y])
            x = par[i][x], y = par[i][y];
    }
    return par[0][x];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    int q;
    cin >> q;
    // has to form a straight line
    // find lca of entire thing
    // just lca everything
    // then we get left and right
    // or we get that it is a straight line
    dfs(1);
    while(q--) {
        int k;
        cin >> k;
        pair<int, int> p[k];
        for(int i = 0; i < k; ++i)
            cin >> p[i].se, p[i].fi = depth[p[i].se];
        int total_lca = p[0].se;
        for(int i = 1; i < k; ++i)
            total_lca = lca(total_lca, p[i].se);
        sort(p, p + k);
        set<int> active;
        bool ans = 1;
        for(auto i : p) {
            // cek apa ada active yang direct par
            if(active.size() > 2)
                break;
            int memo = -1;
            for(auto j : active) {
                //cout << "INFO " << i.se << " " << j << " " << lca(j, i.se) << endl;
                if(lca(j, i.se) == j) {
                    memo = j;
                    break;
                }
                else if(lca(j, i.se) != total_lca) {
                    ans = 0;
                }
            }
            //cout << i.se << " " << memo << endl;
            if(memo == -1)
                active.ins(i.se);
            else {
                active.erase(memo);
                active.ins(i.se);
            }
        }
        if(active.size() <= 2 && ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        //for(auto i : active)
        //    cout << i << " ";
        //cout << endl;
        //cout << (int)ans << endl;
    }
    //for(int i = 1; i <= n; ++i) {
    //    for(int j = 0; j < 3; ++j)
    //        cout << par[j][i] << " ";
    //    cout << endl;
    //}
    return 0;
}