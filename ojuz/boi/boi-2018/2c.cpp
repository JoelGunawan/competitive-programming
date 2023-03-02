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
bool used[5];
vector<int> avail, cur;
vector<vector<int>> combi;
void generate_combi(int n, int idx) {
    if(idx == n) {
        combi.pb(cur);
    }
    for(int i = 0; i < avail.size(); ++i) {
        if(!used[i]) {
            used[i] = 1;
            cur.pb(avail[i]);
            generate_combi(n, idx + 1);
            cur.pop_back();
            used[i] = 0;
        }
    }
}
void generate(int n) {
    for(int i = 1; i <= n; ++i)
        avail.pb(i);
    for(int i = 2; i <= n; ++i) {
        generate_combi(i, 0);
    }
}
const int lim = 3e5 + 5;
int color[lim];
vector<int> edges[lim];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // obs:
    // each edge is only used once
    // each vertex is only used once
    // max path is amount of unique
    // try each permutation?
    int n, m, k;
    cin >> n >> m >> k;
    // try each permutation/combination of colors
    vector<int> tmp2;
    for(int i = 1; i <= k; ++i)
        tmp2.pb(i);
    generate(k);
    for(int i = 1; i <= n; ++i)
        cin >> color[i];
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    ll res = 0;
    for(auto arr : combi) {
        //for(auto i : arr)
        //    cout << i << " ";
        //cout << endl;
        // fi fi nd fi se pr se idx
        queue<pair<pair<int, int>, int>> bfs;
        int ways[n + 1];
        bool vis[n + 1];
        memset(vis, 0, sizeof(vis));
        memset(ways, 0, sizeof(ways));
        for(int i = 1; i <= n; ++i) {
            if(arr[0] == color[i])
                bfs.push(mp(mp(i, 0), 1)), ways[i] = 1;
        }
        while(bfs.size()) {
            int nd = bfs.front().fi.fi, pr = bfs.front().fi.se, idx = bfs.front().se;
            bfs.pop();
            if(idx == arr.size()) {
                res += ways[pr];
                continue;
            }
            ways[nd] += ways[pr];
            if(vis[nd])
                continue;
            vis[nd] = 1;
            for(auto i : edges[nd]) {
                if(arr[idx] == color[i]) {
                    bfs.push(mp(mp(i, nd), idx + 1));
                }
            }
        }
        //cout << res << endl;
    }    
    cout << res << endl;
    return 0;
}