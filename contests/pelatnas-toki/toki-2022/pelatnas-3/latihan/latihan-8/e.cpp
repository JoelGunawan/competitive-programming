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
int k, mod = 1e9 + 7;
struct node {
    int val = 0, lazymul = 1;
    node *l, *r;
};
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
struct dynamic_segment_tree {
    bool inv = 0;
    int sum = 0, nonzero = 0;
    node *head = new node();
    vector<pair<int, int>> updates;
    // maintain entire sum
    void propagate(node *nd, int cl, int cr) {
        if(cl != cr) {
            if(!nd->l)
                nd->l = new node();
            if(!nd->r)
                nd->r = new node();
            nd->l->lazymul = (1ll * nd->l->lazymul * nd->lazymul) % mod;
            nd->r->lazymul = (1ll * nd->r->lazymul * nd->lazymul) % mod;
        }
        nd->val = (1ll * nd->val * nd->lazymul) % mod;
        nd->lazymul = 1;
    }
    void update(node *nd, int cl, int cr, int idx, int val) {
        propagate(nd, cl, cr);
        if(cl == cr) {
            nonzero += val - nd->val;
            sum += val - nd->val;
            nd->val = val;
            return;
        }
        else {
            int mid = (cl + cr) / 2;
            if(idx <= mid)
                update(nd->l, cl, mid, idx, val);
            else
                update(nd->r, mid + 1, cr, idx, val);
        }
    }
    int query(node *nd, int cl, int cr, int idx) {
        if(cl == cr) {
            if(inv)
                return -nd->val;
            else
                return nd->val;
        }
        int mid = (cl + cr) / 2;
        if(idx <= mid && nd->l) {
            propagate(nd, cl, cr);
            return query(nd->l, cl, mid, idx);
        }
        if(idx > mid && nd->r) {
            propagate(nd, cl, cr);
            return query(nd->l, mid + 1, cr, idx);
        }
    }
    void get(node *nd, int cl, int cr) {
        if(cl == cr && nd->val) {
            updates.pb(mp(cl, nd->val));
        }
        int mid = (cl + cr) >> 1;
        bool l = 0, r = 0;
        if(nd->l)
            l = 1;
        if(nd->r)
            r = 1;
        if(l || r) {
            propagate(nd, cl, cr);
            if(l)
                get(nd->l, cl, mid);
            else
                delete nd->l;
            if(r)
                get(nd->r, mid + 1, cr);
            else
                delete nd->r;
        }
        delete nd;
    }
};
const int lim = 3e5 + 5;
bool vis[lim];
vector<int> edges[lim];
int a[lim];
dynamic_segment_tree dynseg[lim];
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
    int get_sz(int nd) {
        return size[find_head(nd)];
    }
    void merge(int x, int y) {
        x = find_head(x), y = find_head(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            size[x] += size[y], head[y] = x;
        }
    }
};
disjoint_set dsu;
bool comp(int x, int y) {
    return dsu.get_sz(x) < dsu.get_sz(y);
}
void dfs(int nd) {
    vis[nd] = 1;
    vector<int> child;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            dfs(i);
            child.pb(i);
        }
    }
    sort(child.begin(), child.end(), comp);
    reverse(child.begin(), child.end());
    for(int i = 1; i < child.size(); ++i) {
        // simpen special index
        // simpen background value (total_sum - default)
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dfs(1);
    
    return 0;
}