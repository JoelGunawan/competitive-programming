// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
const int lim = 3e5 + 5;
struct operation {
    int node, head, size;
    operation(int nd, int h, int s) {
        node = nd, head = h, size = s;
    }
};
ifstream fin("connect.in");
ofstream fout("connect.out");
struct disjoint_set {
    // perlu simpan rollback
    // undo last merge, ubah node ke prev state
    vector<pair<operation, operation>> ops;
    vector<int> changed;
    int head[lim], size[lim];
    int cc = 0;
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
    }
    int find_head(int nd) {
        //fout << nd << endl;
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int x, int y) {
        x = find_head(x), y = find_head(y);
        ops.pb(mp(operation(x, head[x], size[x]), operation(y, head[y], size[y])));
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            size[x] += size[y];
            head[y] = x;
            --cc;
        }
        changed.pb(x != y);
        return x != y;
    }
    void revert() {
        operation tmp1 = ops.back().fi, tmp2 = ops.back().se;
        //fout << tmp1.node << " " << tmp2.node << " " << changed.back() << endl;
        head[tmp1.node] = tmp1.head;
        size[tmp1.node] = tmp1.size;
        head[tmp2.node] = tmp2.head;
        size[tmp2.node] = tmp2.size;
        ops.pop_back();
        cc += changed.back();
        changed.pop_back();
        //fout << cc << endl; 
    }
};
struct segment_tree {
    vector<pair<int, int>> edges[4 * lim];
    int size = lim;
    disjoint_set dsu;
    int ans[lim];
    segment_tree() {
        memset(ans, -1, sizeof(ans));
    }
    void update(int l, int r, int u, int v) {
        update(1, 0, size - 1, l, r, u, v);
    }
    void update(int nd, int cl, int cr, int l, int r, int u, int v) {
        if(cl > r || cr < l)
            return;
        else if(cl >= l && cr <= r)
            edges[nd].pb(mp(u, v));
        else {
            int mid = (cl + cr) / 2;
            update(2 * nd, cl, mid, l, r, u, v);
            update(2 * nd + 1, mid + 1, cr, l, r, u, v);
        }
    }
    void solve(int nd, int l, int r) {
        //fout << nd << " " << l << " " << r << endl;
        if(r < l)
            return;
        for(auto i : edges[nd]) {
            dsu.merge(i.fi, i.se);
            //fout << l << " " << r << " " << i.fi << " " << i.se << endl;
        }
        if(l == r)
            ans[l] = dsu.cc;
        else {
            int mid = (l + r) / 2;
            solve(2 * nd, l, mid);
            solve(2 * nd + 1, mid + 1, r);
        }
        for(auto i : edges[nd])
            dsu.revert();
    }
};
int main() {
    //ios_base::sync_with_stdio(0); fin.tie(0); fout.tie(0);
    int n, k;
    fin >> n >> k;
    segment_tree segtree;
    segtree.dsu.cc = n;
    // bagi jadi semacam segtree dari alive tiap 
    // fi < se
    set<pair<pair<int, int>, int>> active;
    vector<int> questions;
    for(int i = 0; i < k; ++i) {
        char q;
        fin >> q;
        if(q == '?') {
            questions.pb(i);
        }
        else if(q == '-') {
            int u, v;
            fin >> u >> v;
            if(u > v)
                swap(u, v);
            segtree.update((*active.lb(mp(mp(u, v), 0))).se, i, u, v);
            active.erase(active.lb(mp(mp(u, v), 0)));
        }
        else {
            int u, v;
            fin >> u >> v;
            if(u > v)
                swap(u, v);
            active.ins(mp(mp(u, v), i));
        }
    }
    while(active.size()) {
        pair<pair<int, int>, int> tmp = *active.begin();
        active.erase(active.begin());
        segtree.update(tmp.se, k, tmp.fi.fi, tmp.fi.se);
    }
    segtree.solve(1, 0, segtree.size - 1);
    for(auto i : questions)
        fout << segtree.ans[i] << endl;
    return 0;
}