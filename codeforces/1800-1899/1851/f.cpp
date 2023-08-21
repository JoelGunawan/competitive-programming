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
struct node {
    vector<int> a;
    node *l, *r;
};
struct trie_struct {
    int cur, lim, cur_idx;
    node *head = new node();
    // mulai dari k - 1
    void update(node *nd, int idx) {
        nd->a.pb(cur_idx);
        if(idx == -1)
            return;
        if(cur & (1 << idx)) {
            if(!nd->r)
                nd->r = new node();
            update(nd->r, idx - 1);
        }
        else {
            if(!nd->l)
                nd->l = new node();
            update(nd->l, idx - 1);
        }
    }
    // idx mulai dari k - 1
    int query(node *nd, int idx, int val) {
        if(idx == -1)
            return nd->a.front();
        if(val & (1 << idx)) {
            // coba ke kanan 
            if(nd->r) {
                return query(nd->r, idx - 1, val);
            }
            else {
                return query(nd->l, idx - 1, val);
            }
        }
        else {
            // coba ke kiri
            if(nd->l)
                return query(nd->l, idx - 1, val);
            else
                return query(nd->r, idx - 1, val);
        }
    }
    void del(node *nd) {
        if(nd->l)
            del(nd->l);
        if(nd->r)
            del(nd->r);
        delete nd;
    }
};
void tc() {
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // most common, klo gada yg common, cri second most common
    // bs pake trie aja
    trie_struct t;
    pair<int, pair<int, int>> mx = mp(-1, mp(0, 0));
    for(int i = 1; i <= n; ++i) {
        if(i != 1) {
            int e = t.query(t.head, k - 1, a[i]);
            t.cur = a[i];
            t.cur_idx = i;
            t.update(t.head, k - 1);
            int cur = 0;
            for(int j = 0; j < k; ++j) {
                if(((1 << j) & a[i]) == ((1 << j) & a[e]))
                    cur += 1 << j;
            }
            //cout << "DEB " << i << " " << e << " " << cur << endl;
            if(cur > mx.fi) {
                mx.fi = cur;
                mx.se.fi = e;
                mx.se.se = i;
            }
        }
        else {
            t.cur = a[i];
            t.cur_idx = i;
            t.update(t.head, k - 1);
        }
    }
    cout << mx.se.fi << " " << mx.se.se << " ";
    // klo sama tp 0 di xor
    int x = 0;
    for(int i = 0; i < k; ++i) {
        if((((1 << i) & a[mx.se.fi]) == 0) && (((1 << i) & a[mx.se.se]) == 0))
            x += 1 << i;
    }
    cout << x << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // cari most common mulai dari yg paling besar
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}