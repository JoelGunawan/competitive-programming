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
            size[x] += size[y];
            head[y] = x;
        }
        return x != y;
    }
};
vector<pair<int, int>> mst[lim];
vector<pair<int, int>> edges[lim];
struct small_to_large {
    int head[lim], size[lim];
    // fi -> weight
    // se -> node tujuan
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq[lim];
    small_to_large() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
    }
    int find_head(int nd) {
        return head[nd] == -1 ? nd : head[nd] = find_head(head[nd]);
    }
    bool merge(int x, int y) {
        x = find_head(x), y = find_head(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            size[x] += size[y];
            head[y] = x;
            //cout << "PRE " << pq[x].size() << " " << pq[y].size() << endl;
            if(pq[x].size() < pq[y].size())
                swap(pq[x], pq[y]);
            while(pq[y].size())
                pq[x].push(pq[y].top()), pq[y].pop();
            //cout << "POST " << pq[x].size() << " " << pq[y].size() << endl;
        }
        return x != y;
    }
};
small_to_large stl;
int mx = 0;
bool vis[lim];
int par[lim];
void dfs(int nd) {
    // dfs menurut stl
    vis[nd] = 1;
    //cout << nd << endl;
    //cout.flush();
    for(auto i : mst[nd]) {
        if(!vis[i.fi]) {
            par[i.fi] = i.se;
            dfs(i.fi);
            stl.merge(nd, i.fi);
        }
    }
    int curh = stl.find_head(nd);
    while(stl.pq[curh].size() && stl.find_head(stl.pq[curh].top().se) == curh) {
        //cout << "POP " << nd << " " << stl.pq[curh].top().fi << " " << stl.pq[curh].top().se << endl;
        stl.pq[curh].pop();
    }
    //cout << "ND DONE " << nd << endl;
    //cout.flush();
    //cout << "DEBUG " << nd << " " << stl.pq[curh].size() << endl;
    if(stl.pq[curh].size()) {
        //cout << stl.pq[curh].top().fi << " " << par[nd] << endl;
        mx = max(mx, stl.pq[curh].top().fi - par[nd]);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> adj;
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj.pb(mp(w, mp(u, v)));
        edges[u].pb(mp(v, w));
        edges[v].pb(mp(u, w));
    }
    disjoint_set dsu;
    sort(adj.begin(), adj.end());
    vector<pair<int, pair<int, int>>> mst_adj;
    ll old = 0;
    for(auto p : adj) {
        if(dsu.merge(p.se.fi, p.se.se)) {
            mst[p.se.fi].pb(mp(p.se.se, p.fi));
            mst[p.se.se].pb(mp(p.se.fi, p.fi));
            mst_adj.pb(mp(p.fi, mp(min(p.se.fi, p.se.se), max(p.se.se, p.se.fi))));
            old += p.fi;
        }
    }
    //cout << "TEST" << endl;
    //cout.flush();
    sort(mst_adj.begin(), mst_adj.end());
    // GUARANTEED: NO BRIDGE
    // pilih root, terus nanti pakai small to large algo buat simpan cost keluar paling kecil dalam pq
    // dfs, terus simpan
    for(int i = 1; i <= n; ++i) {
        for(auto j : edges[i]) {
            if(!binary_search(mst_adj.begin(), mst_adj.end(), mp(j.se, mp(min(j.fi, i), max(j.fi, i)))))
                stl.pq[i].push(mp(j.se, j.fi));
        }
    }
    //cout << "TEST" << endl;
    //cout.flush();
    dfs(1);
    cout << old + mx << endl;
    return 0;
}