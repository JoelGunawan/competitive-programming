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
    int val = -1e9;
    node *l, *r;
};
struct segment_tree {
    node *head = new node();
    int dl = 0, dr = 1e6;
    int query(node *nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r) {
            return nd->val;
        }
        else if(cl > r || cr < l ) {
            return -1e9;
        }
        else {
            int mid = (cl + cr) / 2;
            int ret = -1e9;
            if(nd->l)
                ret = max(ret, query(nd->l, cl, mid, l, r));
            if(nd->r)
                ret = max(ret, query(nd->r, mid + 1, cr, l, r));
            return ret;
        }
    }
    int query(int l, int r) {
        return query(head, dl, dr, l, r);
    }
    void update(node *nd, int cl, int cr, int idx, int val) {
        //cout << cl - 1e15 << " " << cr - 1e15 << endl;
        if(cl == cr) {
            nd->val = max(val, nd->val);
            return;
        }
        int mid = (cl + cr) / 2;
        if(idx <= mid) {
            if(!nd->l) {
                nd->l = new node();
            }
            update(nd->l, cl, mid, idx, val);
            if(nd->r)
                nd->val = max(nd->l->val, nd->r->val);
            else
                nd->val = nd->l->val;
        }
        else {
            if(!nd->r) {
                nd->r = new node();
            }
            update(nd->r, mid + 1, cr, idx, val);
            if(nd->l)
                nd->val = max(nd->l->val, nd->r->val);
            else
                nd->val = nd->r->val;
        }
    }
    void update(int idx, int val) {
        update(head, dl, dr, idx, val);
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
    int n;
    cin >> n;
    long long a[n + 1], pref[n + 1];
    vector<long long> pref_vals = {0};
    pref[0] = 0;
    //cout << "HERE" << endl;
    map<int, int> same;
    map<int, bool> vis;
    segment_tree pos, neg;
    for(int i = 1; i <= n; ++i)
        cin >> a[i], pref[i] = pref[i - 1] + a[i], pref_vals.pb(pref[i]);
    sort(pref_vals.begin(), pref_vals.end());
    pref_vals.resize(unique(pref_vals.begin(), pref_vals.end()) - pref_vals.begin());
    for(int i = 0; i <= n; ++i)
        pref[i] = lower_bound(pref_vals.begin(), pref_vals.end(), pref[i]) - pref_vals.begin();
    //cout << "HERE2" << endl;
    vis[pref[0]] = 1;
    pos.update(pref[0], 0);
    neg.update(pref[0], 0);
    //cout << "CHECK!" << endl;
    for(int i = 1; i <= n; ++i) {
        // try maximum of all
        int res;
        //cout << "TEST1" << endl;
        //cout << "FIND " << pref[i] << " " << neg.query(pref[i] + 1, n + 1) << " " << pos.query(0, pref[i] - 1) << endl;
        //cout << i << " " << pref[i] << endl;
        if(vis[pref[i]]) {
            res = max({pos.query(0, pref[i] - 1) + i, neg.query(pref[i] + 1, n + 1) - i, same[pref[i]]});
            same[pref[i]] = max(same[pref[i]], res);
            pos.update(pref[i], res - i);
            neg.update(pref[i], res + i);
        }
        else {
            res = max(pos.query(0, pref[i] - 1) + i, neg.query(pref[i] + 1, n + 1) - i);
            vis[pref[i]] = 1;
            same[pref[i]] = res;
            pos.update(pref[i], res - i);
            neg.update(pref[i], res + i);
        }
        //cout << "TEST2" << endl;
        //cout << res << endl;
        //cout << res << " ";
        if(i == n)
            cout << res << endl;
    }
    pos.del(pos.head);
    neg.del(neg.head);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}