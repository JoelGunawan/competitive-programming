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
const int lim = 5e3 + 5;
vector<int> edges[lim], child[lim];
int depth[lim];
int dfs(int nd) {
    int res = 0, depthsum = 0;
    for(auto i : child[nd]) {
        res += dfs(i);
        depthsum += depth[i];
    }
    depth[nd] = depthsum + 1;
    res += depthsum + 1; 
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // bfs inv edge
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        while(k--) {
            int x;
            cin >> x;
            if(x >= 1 && x <= n && x != i)
                edges[x].pb(i);
        }
    }
    // bfs cari max antara semua child + 1
    // create bfs tree for every root
    // pastikan bfs tree ukuran n
    // get result
    int res = 1e9;
    for(int i = 1; i <= n; ++i) {
        // create bfs tree
        bool vis[n + 1];
        memset(vis, 0, sizeof(vis));
        memset(depth, 0, sizeof(depth));
        queue<pair<int, int>> bfs;
        bfs.push(mp(i, 0));
        for(int i = 0; i <= n; ++i)
            child[i].clear();
        int cnt = 0;
        while(bfs.size()) {
            int nd = bfs.front().fi, pr = bfs.front().se;
            bfs.pop();
            if(vis[nd])
                continue;
            ++cnt;
            child[pr].pb(nd);
            vis[nd] = 1;
            //cout << "BFS " << nd << " " << pr << endl;
            //cout << "EDGES " << nd << endl;
            for(auto i : edges[nd]) {
                //cout << i << " ";
                if(!vis[i]) {
                    bfs.push(mp(i, nd));
                }
            }
            //cout << endl;
        }
        if(cnt == n)
            res = min(res, dfs(i));
    }
    cout << res << endl;
    return 0;
}