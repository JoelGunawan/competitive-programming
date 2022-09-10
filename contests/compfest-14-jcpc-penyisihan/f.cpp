// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
#define endl "\n"
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
/*
struct node {
    int val = 0, lazy = 0;
    node *l = nullptr, *r = nullptr;
};
struct segment_tree {
    node *head = new node();
    void clear(node *nd) {
        if(nd->l)
            clear(nd->l);
        if(nd->r)
            clear(nd->r);
        delete nd;
    }
    void propagate(node *nd, int cl, int cr) {
        if(!nd->l)
            nd->l = new node();
        if(!nd->r)
            nd->r = new node();
        if(cl != cr) {
            nd->l->lazy += nd->lazy;
            nd->r->lazy += nd->lazy;
        }
        nd->val += nd->lazy;
        nd->lazy = 0;
    }
    void update(node *nd, int cl, int cr, int l, int r, int val) {
        if(cl > r || cr < l)
            return;
        else if(cl >= l && cr <= r) {
            nd->lazy += val;
            propagate(nd, cl, cr);
        }
        else {
            propagate(nd, cl, cr);
            int mid = (cl + cr) >> 1;
            update(nd->l, cl, mid, l, r, val);
            update(nd->r, mid + 1, cr, l, r, val);
            nd->val = max(nd->l->val, nd->r->val);
        }
    }
};
*/
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi >> a[i].se;
    int q;
    cin >> q;
    int w[q];
    for(int i = 0; i < q; ++i)
        cin >> w[i];
    vector<pair<int, bool>> sweep[30];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 30; ++j) {
            if(a[i].se - a[i].fi + 1 >= 1 << j) {
                sweep[j].pb(mp(0, 0));
            }
            else if(a[i].fi % (1 << j) > a[i].se % (1 << j)) {
                sweep[j].pb(mp(a[i].fi % (1 << j), 0));
                sweep[j].pb(mp(a[i].se % (1 << j), 1));
                sweep[j].pb(mp(0, 0));
                sweep[j].pb(mp((1 << j) - 1, 1));
            }
            else {
                sweep[j].pb(mp(a[i].fi % (1 << j), 0));
                sweep[j].pb(mp(a[i].se % (1 << j), 1));
            }
        }
    }
    for(int j = 0; j < 30; ++j) {
        sort(sweep[j].begin(), sweep[j].end());
    }
    int ans[30];
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < 30; ++i) {
        int cnt = 0;
        for(auto j : sweep[i]) {
            if(j.se)
                --cnt;
            else
                ++cnt, ans[i] = max(ans[i], cnt);
        }
    }
    for(int i = 0; i < q; ++i) {
        int lsb;
        for(int j = 0; j < 30; ++j) {
            if((1 << j) & w[i]) {
                lsb = j;
                break;
            }
        }
        cout << ans[lsb] << endl;
    }
    return 0;
}