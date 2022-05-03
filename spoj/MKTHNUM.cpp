// header file
#include <bits/stdc++.h>
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
struct node {
    int val = 0;
    node *l = nullptr, *r = nullptr;
    node() {

    }
    node(node *le, node *re) {
        l = le, r = re;
        if(l)
            val += l->val;
        if(r);
            val += r->val;
    }
};
struct segment_tree {
    vector<node*> a = {new node()};
    node *empty = new node();
    int size = 1e9 + 1e5;
    void update(node *nd, node *prev, int cl, int cr, int idx, int val) {
        int mid = (cl + cr) / 2;
        if(cl == cr) {
            nd->val = prev->val + val;
        }
        else if(idx <= mid) {
            nd->l = new node();
            nd->r = prev->r;
            if(prev->l != nullptr)
                update(nd->l, prev->l, cl, mid, idx, val);
            else
                update(nd->l, empty, cl, mid, idx, val);
            if(nd->l)
                nd->val += nd->l->val;
            if(nd->r)
                nd->val += nd->r->val;
        }
        else {
            nd->l = prev->l;
            nd->r = new node();
            if(prev->r != nullptr)
                update(nd->r, prev->r, mid + 1, cr, idx, val);
            else
                update(nd->r, empty, mid + 1, cr, idx, val);
            if(nd->l)
                nd->val += nd->l->val;
            if(nd->r)
                nd->val += nd->r->val;
        }
    }
    void update(int idx, int val) {
        a.pb(new node());
        update(a[a.size() - 1], a[a.size() - 2], 1, size, idx, val);
    }
    int query(node *l, node *r, int cl, int cr, int k) {
        int mid = (cl + cr) / 2;
        int tmpr = 0, tmpl = 0;
        if(cl == cr)
            return cl;
        if(r->l != nullptr)
            tmpr = r->l->val;
        if(l->l != nullptr)
            tmpl = l->l->val;
        // count di kiri ga sampe k
        // berarti k nya di kanan
        if(tmpr - tmpl < k) {
            if(l->r != nullptr)
                return query(l->r, r->r, mid + 1, cr, k - (tmpr - tmpl));
            else
                return query(empty, r->r, mid + 1, cr, k - (tmpr - tmpl));
        }
        else {
            if(l->l != nullptr)
                return query(l->l, r->l, cl, mid, k);
            else
                return query(empty, r->l, cl, mid, k);
        }
    }
    int query(int l, int r, int k) {
        return query(a[l - 1], a[r], 1, size, k);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n], b[n];
    segment_tree seg;
    for(int i = 0; i < n; ++i)
        cin >> a[i], b[i] = a[i];
    map<int, int> x, y;
    sort(b, b + n);
    for(int i = 0; i < n; ++i) {
        x[b[i]] = i + 1;
        y[i + 1] = b[i];
    }
    for(int i = 0; i < n; ++i)
        seg.update(x[a[i]], 1);
    for(int i = 0; i < m; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << y[seg.query(l, r, k)] << endl;
    }
    return 0;
}