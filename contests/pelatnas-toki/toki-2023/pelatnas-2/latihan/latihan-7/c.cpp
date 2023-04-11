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
int mod = 1e9, ti = 0;
struct node {
    int cl, cr, id;
    ll val = 1;
    node *l, *r;
    node() {
        id = ti++;
    }
};
typedef node * pnode;
struct segment_tree {
    pnode head = new node();
    void update(pnode nd, int idx, int val) {
        int mid = (nd->cl + nd->cr) / 2;
        if(nd->cl == nd->cr) {
            nd->val = val;
            return;
        }
        if(idx <= mid) {
            if(!nd->l) {
                nd->l = new node();
                nd->l->cl = nd->cl;
                nd->l->cr = mid;
            }
            update(nd->l, idx, val);
        }
        else {
            if(!nd->r) {
                nd->r = new node();
                nd->r->cl = mid + 1;
                nd->r->cr = nd->cr;
            }
            update(nd->r, idx, val);
        }
        nd->val = 1;
        if(nd->l)
            nd->val *= nd->l->val;
        if(nd->r)
            nd->val *= nd->r->val;
        nd->val %= mod;
    }
    void pers_upd(pnode nd, pnode old, int idx, int val) {
        int mid = (nd->cl + nd->cr) / 2;
        if(nd->cl == nd->cr) {
            nd->val = val;
            //cout << "PERS UPD " << nd->cl << " " << nd->val << " " << nd->id << endl;
            return;
        }
        if(idx <= mid) {
            if(!nd->l) {
                nd->l = new node();
                nd->l->cl = nd->cl;
                nd->l->cr = mid;
            }
            pers_upd(nd->l, old->l, idx, val);
            if(old->r)
                nd->r = old->r;
        }
        else {
            if(!nd->r) {
                nd->r = new node();
                nd->r->cl = mid + 1;
                nd->r->cr = nd->cr;
            }
            pers_upd(nd->r, old->r, idx, val);
            if(old->l)
                nd->l = old->l;
        }
        nd->val = 1;
        if(nd->l)
            nd->val *= nd->l->val;
        if(nd->r)
            nd->val *= nd->r->val;
        //cout << "PERS " << nd->cl << " " << nd->cr << " " << nd->val << " " << nd->id << endl;
        //cout << "SEC " << old->val << " " << old->id << " ";
        //if(old->l)
        //    cout << old->l->id << " ";
        //if(old->r) 
        //    cout << old->r->id << " ";
        //cout << endl;
        nd->val %= mod;
    }
    void replace(pnode nd, pnode nx, int l, int r) {
        if(nd->cl >= l && nd->cr <= r) {
            // replace nd with nx
            return;
        }
        else if(nd->cl > r || nd->cr < l) {
            return;
        }
        else {
            nd->val = 1;
            if(nd->l) {
                if(nd->l->cl >= l && nd->l->cr <= r) {
                    nd->l = nx->l;
                }
                else 
                    replace(nd->l, nx->l, l, r); 
                nd->val *= nd->l->val;
            }
            if(nd->r) {
                if(nd->r->cl >= l && nd->r->cr <= r) {
                    nd->r = nx->r;
                }
                else
                    replace(nd->r, nx->r, l, r);
                nd->val *= nd->r->val;
            }
            nd->val %= mod;
            //cout << "DEBUG REPLACE" << endl;
            //cout << nd->cl << " " << nd->cr << " " << nd->id << " " << nx->id << endl;
            //if(nd->l)
            //    cout << nd->l->id << " " << nx->l->id << endl;
            //if(nd->r)
            //    cout << nd->r->id << " " << nx->r->id << endl;
        }
    }
    ll query(pnode nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r) {
            //cout << "DEBUG " << cl << " " << cr << " " << nd->val << " " << nd->id << endl;
            return nd->val % mod;
        }
        else if(cr < l || cl > r)
            return 1;
        else {
            int mid = (cl + cr) / 2;
            ll res = 1;
            if(nd->l)
                res *= query(nd->l, cl, mid, l, r);
            if(nd->r)
                res *= query(nd->r, mid + 1, cr, l, r);
            return res % mod;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    segment_tree a, b;
    b.head->cl = a.head->cl = 1, b.head->cr = a.head->cr = n;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a.update(a.head, i, x);
    }
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        b.update(b.head, i, x);
    }
    for(int i = 1; i <= q; ++i) {
        // pake konsep persistent segtree
        int t;
        cin >> t;
        if(t == 1) {
            // update dengan konsep persistent :D
            // hapus node lama yg tidak terpakai? tapi tidak tahu
            // jadi biarkan memory leak aja :D
            int pos, val;
            cin >> pos >> val;
            node *tmp = new node();
            tmp->cl = 1, tmp->cr = n;
            a.pers_upd(tmp, a.head, pos, val);
            a.head = tmp;
        }
        else if(t == 2) {
            // change all nodes with head at this index to new
            int l, r;
            cin >> l >> r;
            a.replace(a.head, b.head, l, r);
        }
        else if(t == 3) {
            int l, r;
            cin >> l >> r;
            cout << a.query(a.head, 1, n, l, r) << endl;           
        }
        else if(t == 4) {
            int pos, val;
            cin >> pos >> val;
            node *tmp = new node();
            tmp->cl = 1, tmp->cr = n;
            b.pers_upd(tmp, b.head, pos, val);
            b.head = tmp;
        }
        else if(t == 5) {
            int l, r;
            cin >> l >> r;
            b.replace(b.head, a.head, l, r);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << b.query(b.head, 1, n, l, r) << endl;    
        }
    }
    return 0;
}