// header file
#include <bits/stdc++.h>
// pragma
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
const int lim = 1 << 18;
struct node {
    int val = -1;
    node *l = nullptr, *r = nullptr;
};
struct segtree {
    node *head = new node();
    void update(int idx, int val) {
        if(idx < 0 || idx >= lim)
            return;
        // set a[idx] to max(a[idx], val)
        update(head, 0, lim - 1, idx, val);
    }
    void update(node *nd, int l, int r, int idx, int val) {
        nd->val = max(val, nd->val);
        int mid = (l + r) / 2;
        if(l == r)
            return;
        else if(idx <= mid) {
            if(!nd->l)
                nd->l = new node();
            update(nd->l, l, mid, idx, val);
        }
        else {
            if(!nd->r)
                nd->r = new node();
            update(nd->r, mid + 1, r, idx, val);
        }
    }
    int query(int l, int r) {
        if(l > r)
            return -1;
        return query(head, 0, lim - 1, l, r);
    }
    int query(node *nd, int cl, int cr, int l, int r) {
        if(!nd || cl > r || cr < l)
            return -1;
        else if(cl >= l && cr <= r)
            return nd->val;
        else {
            int mid = (cl + cr) / 2;
            return max(query(nd->l, cl, mid, l, r), query(nd->r, mid + 1, cr, l, r));
        }
    }
};
struct node_2d {
    int val = -1;
    node_2d *ul = nullptr, *ur = nullptr, *dl = nullptr, *dr = nullptr;
};
struct segtree_2d {
    node_2d *head = new node_2d();
    // KOK 2D SIH
    int size = lim;
    void update(int x, int y, int val) {
        if(x < 0 || y < 0 || x >= lim || y >= lim)
            return;
        update(head, 0, size - 1, 0, size - 1, x, y, val);
    }
    void update(node_2d *nd, int cl, int cr, int cd, int cu, int x, int y, int val) {
        //cout << "UPD " << cl << " " << cr << " " << cd << " " << cu << " " << x << " " << y << endl;
        nd->val = max(nd->val, val);
        int midx = (cl + cr) / 2, midy = (cd + cu) / 2;
        assert((cl == cr) == (cd == cu));
        if(cl == cr && cd == cu)
            return;
        else if(x <= midx) {
            if(y <= midy) {
                if(!nd->dl)
                    nd->dl = new node_2d();
                update(nd->dl, cl, midx, cd, midy, x, y, val);
            }
            else {
                if(!nd->ul) 
                    nd->ul = new node_2d();
                update(nd->ul, cl, midx, midy + 1, cu, x, y, val);
            }
        }
        else {
            if(y <= midy) {
                if(!nd->dr)
                    nd->dr = new node_2d();
                update(nd->dr, midx + 1, cr, cd, midy, x, y, val);
            }
            else {
                if(!nd->ur)
                    nd->ur = new node_2d();
                update(nd->ur, midx + 1, cr, midy + 1, cu, x, y, val);
            }
        }
    }
    int query(int l, int r, int d, int u) {
        //cout << l << " " << r << " " << d << " " << u << endl;
        if(r < l || u < d)
            return -1;
        return query(head, 0, size - 1, 0, size - 1, l, r, d, u);
    }
    int query(node_2d *nd, int cl, int cr, int cd, int cu, int l, int r, int d, int u) {
        //cout << "QUERY " << cl << " " << cr << " " << cd << " " << cu << endl;
        if(cl > r || cr < l || cd > u || cu < d || !nd)
            return -1;
        else if(cl >= l && cr <= r && cd >= d && cu <= u) {
            return nd->val;
        }
        else {
            int midx = (cl + cr) / 2, midy = (cd + cu) / 2;
            return max(max(query(nd->dl, cl, midx, cd, midy, l, r, d, u), query(nd->ul, cl, midx, midy + 1, cu, l, r, d, u))
            , max(query(nd->dr, midx + 1, cr, cd, midy, l, r, d, u), query(nd->ur, midx + 1, cr, midy + 1, cu, l, r, d, u)));
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // pake pending update O(sqrt) technique
    // O(nlog^2)
    // pake 2d dynamic segtree dan 1d dynamic segtree
    // simpen segtree max z for given y
    // simpen segtree max y for given z
    // update segtree
    int n;
    cin >> n;
    pair<int, pair<int, int>> a[n];
    set<int> e, f;
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi >> a[i].se.fi >> a[i].se.se, e.ins(a[i].se.fi), f.ins(a[i].se.se);
    map<int, int> y, z;
    int cnt = 1;
    for(auto i : e)
        y[i] = cnt++;
    cnt = 1;
    for(auto i : f)
        z[i] = cnt++;
    sort(a, a + n);
    // update only if x already changed
    int px = -1;
    segtree_2d d;
    segtree b, c;
    vector<pair<int, int>> pending;
    int res = -1;
    for(int i = 0; i < n; ++i) {
        if(a[i].fi == px) {
            // add to pending
            pending.pb(a[i].se);
        }
        else {
            // clear pending
            //cout << i << endl;
            for(auto i : pending) {
                // b segtree -> max z based on y
                // c segtree -> max y based on z
                // add based on y
                //cout << i.fi << " " << i.se << endl;
                if(b.query(0, y[i.fi] - 1) > 0 && b.query(1, y[i.fi] - 1) > i.se) {
                    //cout << "UPDATE " << i.fi << " " << b.query(1, i.fi - 1) << endl;
                    d.update(y[i.fi], z[b.query(1, y[i.fi] - 1)], i.fi + b.query(1, y[i.fi] - 1));
                }
                // add based on z
                if(c.query(0, z[i.se] - 1) > 0 && c.query(0, z[i.se] - 1) > i.fi) {
                    //cout << "UPDATE " << c.query(1, i.se - 1) << " " << i.se << endl;
                    d.update(y[c.query(0, z[i.se] - 1)], z[i.se], c.query(0, z[i.se] - 1) + i.se);
                }
                b.update(y[i.fi], i.se);
                c.update(z[i.se], i.fi);
            }
            pending.clear();
            pending.pb(a[i].se);
            px = a[i].fi;
        }
        int tmp = d.query(y[a[i].se.fi] + 1, lim - 1, z[a[i].se.se] + 1, lim - 1);
        //cout << a[i].se.fi + 1 << " " << a[i].se.se + 1 << " " << tmp << endl;
        if(tmp != -1)
            res = max(res, tmp + a[i].fi);
    }
    cout << res << endl;
    return 0;
}