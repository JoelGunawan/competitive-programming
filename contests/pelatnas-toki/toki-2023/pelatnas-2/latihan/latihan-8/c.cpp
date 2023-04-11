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
const int lim = 5e4 + 5;
int low[lim], disc[lim], t = 0;
bool active[lim];
vector<int> edges[lim];
vector<int> cur_cmp, tot_cmp;
void dfs(int nd = 1) {
    low[nd] = disc[nd] = t++;
    active[nd] = 1;
    cur_cmp.pb(nd);
    for(auto i : edges[nd]) {
        if(disc[i] == -1)  {
            dfs(i);
            low[nd] = min(low[nd], low[i]);
        } 
        else
            low[nd] = min(low[nd], disc[i]);
    }
    if(low[nd] == disc[nd]) {
        // pop stack sampe ketemu
        tot_cmp.clear();
        while(cur_cmp.back() != nd) {
            tot_cmp.pb(cur_cmp.back());
            cur_cmp.pop_back();
        }
        tot_cmp.pb(cur_cmp.back());
        cur_cmp.pop_back();
    }
    active[nd] = 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // graf terhubung
    // euler path?
    // graf harus merupakan scc
    // graf ada odd cycle sm even cycle
    // dfs tree utk cari scc
    // nanti habis dfs tree bs dijkstra aja semua state :D
    // gcd of all possible cycle lengths

    int n, m;
    cin >> n >> m;
    if(n == 1)
        cout << "Ya" << endl, exit(0);
    vector<int> adj[n + 1][2];
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        adj[u][0].pb(v);
        adj[u][1].pb(v);
    }
    memset(disc, -1, sizeof(disc));
    dfs(1);
    //for(auto i : tot_cmp) {
    //    cout << i << " ";
    //}
    if(tot_cmp.size() != n)
        cout << "Tidak" << endl, exit(0);
    // cari cycle len even dan cycle len odd
    int vis[n + 1];
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;
    q.push(mp(1, 0));
    // find even length cycles and odd length cycles
    bool ev = 0, od = 0;
    // after use edge erase to avoid confusion
    int gcd = 0;
    while(q.size()) {
        int nd = q.front().fi, par = q.front().se;
        q.pop();
        if(vis[nd]) {
            if(__gcd(par - vis[nd], gcd) == gcd)
                continue;
            else {
                gcd = __gcd(par - vis[nd], gcd);
            }
        }
        vis[nd] = par;
        // gcd of cycle harus 1
        while(adj[nd][par & 1].size()) {
            q.push(mp(adj[nd][par & 1].back(), par + 1));
            adj[nd][par & 1].pop_back();
        }
    }
    // ex -> try to find cycle of certain length
    // ada edge lain, berarti bs buat cycle yg lengthnya itu sepanjang diff
    // find length of all paths menuju 1
    // find diff between 
    if(gcd == 1)
        cout << "Ya" << endl;
    else
        cout << "Tidak" << endl;
    return 0;
}