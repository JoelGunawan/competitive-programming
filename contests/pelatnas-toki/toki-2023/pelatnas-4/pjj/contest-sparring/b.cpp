#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
using namespace std;
const int lim = 1e5 + 5;
vector<int> edges[lim];
bool vis[lim];
int in[lim], out[lim], to_nd[lim], ti, depth[lim];
int par[17][lim];
void get_ett(int nd) {
    vis[nd] = 1;
    in[nd] = ++ti;
    to_nd[in[nd]] = nd;
    for(int i = 1; i < 17; ++i)
        par[i][nd] = par[i - 1][par[i - 1][nd]];
    for(auto i : edges[nd]) {
        if(!vis[i])
            depth[i] = depth[nd] + 1, par[0][i] = nd, get_ett(i);
    }
    out[nd] = ti;
}
int lca(int u, int v) {
    if(depth[u] > depth[v])
        swap(u, v);
    for(int i = 16; i >= 0; --i) {
        if(depth[par[i][v]] >= depth[u])
            v = par[i][v];
    }
    if(u == v)
        return u;
    for(int i = 16; i >= 0; --i) {
        if(par[i][v] != par[i][u])
            u = par[i][u], v = par[i][v];
    }
    return par[0][u];
}
struct fenwick {
    int a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        //cout << "UPDATE " << idx << " " << val << endl;
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    int query(int idx) {
        int ret = 0;
        while(idx) {
            ret += a[idx];
            idx -= idx&-idx;
        }
        return ret;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
fenwick bit;
int cur_cnt = 0, cur_lca;
multiset<int> nodes;
void insert(int node) {
    if(cur_cnt == 0) {
        cur_cnt = 1;
        cur_lca = node;
        nodes.insert(in[node]);
        bit.update(in[node], 1);
        return;
    }
    int nlca = lca(node, cur_lca);
    if(nlca != cur_lca) {
        // lca nya baru
        // berarti tambahin lgsg aja
        cur_cnt += depth[cur_lca] + depth[node] - 2 * depth[nlca];
        nodes.insert(in[node]);
        bit.update(in[node], 1);
        cur_lca = nlca;
        //cout << "PRI " << node << " " << cur_cnt << endl;
    }
    else {
        // bagi kasus
        // klo ada children, berarti ga tambah
        // kalo ga ada children,  
        if(bit.query(in[node], out[node])) {
            nodes.insert(in[node]);
            bit.update(in[node], 1);
        }
        else {
            // dia cari closest lca antara di kiri atau di kanan
            // cari max depth
            int mx_lca_d = 0;
            if(nodes.lower_bound(in[node]) != nodes.end()) {
                mx_lca_d = max(mx_lca_d, depth[lca(node, to_nd[*nodes.lower_bound(in[node])])]);
            } 
            if(nodes.lower_bound(in[node]) != nodes.begin()) {
                mx_lca_d = max(mx_lca_d, depth[lca(node, to_nd[*--nodes.lower_bound(in[node])])]);
            }
            nodes.insert(in[node]);
            bit.update(in[node], 1);
            //cout << mx_lca_d << " " << depth[node] << endl;
            cur_cnt += depth[node] - mx_lca_d;
        }
        //cout << "SEC " << node << " " << cur_cnt << endl;
    }
}
void erase(int node) {
    //cout << "ADA ERASE " << node << endl;
    assert(nodes.find(in[node]) != nodes.end());
    if(cur_cnt == 1) {
        cur_cnt = 0, cur_lca = -1, nodes.clear();
        bit.update(in[node], -1);
        return;
    }
    nodes.erase(nodes.find(in[node]));
    bit.update(in[node], -1);
    //cout << "QUERY " << in[node] << " " << out[node] << " " << bit.query(in[node], out[node]) << endl;
    if(bit.query(in[node], out[node])) {
        // berarti masih ada di child
        //cout << "ADA CHILD" << endl;
        // coba cari new lca
        // kalo ganti, berarti skrg merupakan root, pergi ke lower lca
        int nlca = lca(to_nd[*nodes.begin()], to_nd[*--nodes.end()]);
        if(nlca != cur_lca) {
            // tidak sama dengan -> remove node sebanyak nlca - cur_lca
            cur_cnt -= depth[nlca] - depth[cur_lca];
            cur_lca = nlca;
        }
        // sama dengan -> tidak ada perubahan
    }
    else {
        // tidak ada di child
        // berarti merupakan leaf
        // coba cri maxd lca di kiri/kanan
        // dikurangi sebanyak itu
        //cout << "NO CHILD" << endl;
        int max_d = 0;
        if(nodes.lower_bound(in[node]) != nodes.end()) {
            max_d = max(max_d, depth[lca(node, to_nd[*nodes.lower_bound(in[node])])]);
        }
        if(nodes.lower_bound(in[node]) != nodes.begin()) {
            max_d = max(max_d, depth[lca(node, to_nd[*--nodes.lower_bound(in[node])])]);
        }
        //cout << "MAX DEPTH " << max_d << endl;
        cur_cnt -= depth[node] - max_d;
        int nlca = lca(to_nd[*nodes.begin()], to_nd[*--nodes.end()]);
        if(nlca != cur_lca) {
            //cout << "CHANGE LCA " << nlca << " " << cur_lca << endl;
            cur_cnt -= depth[nlca] - depth[cur_lca];
            cur_lca = nlca;
        }
    }
    //cout << "RET " << cur_cnt << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    depth[1] = 1;
    get_ett(1);
    int c[m + 1];
    for(int i = 1; i <= m; ++i)
        cin >> c[i];
    memset(vis, 0, sizeof(vis));
    int sz = sqrt(n);
    vector<pair<pair<int, int>, int>> blk[n / sz + 2];
    int ans[q + 1];
    for(int i = 1; i <= q; ++i) {
        int l, r;
        cin >> l >> r;
        blk[l / sz].push_back({make_pair(r, l), i});
    }
    for(int i = 0; i < n / sz + 2; ++i)
        sort(blk[i].begin(), blk[i].end());
    for(int i = 0; i < n / sz + 2; ++i) {
        cur_cnt = 0;
        for(auto i : nodes)
            bit.update(i, -1);
        nodes.clear();
        int cur_l = -1, cur_r = -1;
        for(auto j : blk[i]) {
            if(cur_cnt == 0) {
                cur_l = j.fi.se, cur_r = j.fi.se;
                nodes.insert(in[c[j.fi.se]]);
                bit.update(in[c[j.fi.se]], 1);
                cur_cnt = 1;
                cur_lca = c[j.fi.se];
            }
            //cout << cur_l << " " << cur_r << endl;
            //cout << *nodes.begin() << endl;
            // expand left
            while(cur_l > j.fi.se) {
                insert(c[cur_l - 1]);
                --cur_l;
            }
            // expand right
            while(cur_r < j.fi.fi) {
                insert(c[cur_r + 1]);
                ++cur_r;
            }
            // shrink left
            while(cur_l < j.fi.se) {
                erase(c[cur_l]);
                ++cur_l;
            }
            while(cur_r > j.fi.fi) {
                erase(c[cur_r]);
                --cur_r;
            }
            //cout << cur_l << " " << cur_r << endl;
            //for(int i = cur_l; i <= cur_r; ++i)
            //    cout << c[i] << " ";
            //cout << endl;
            //cout << "NODES" << endl;
            //for(auto i : nodes)
            //    cout << to_nd[i] << " ";
            //cout << endl;
            ans[j.se] = cur_cnt;
        }
    }   
    for(int i = 1; i <= q; ++i)
        cout << ans[i] << endl;
}