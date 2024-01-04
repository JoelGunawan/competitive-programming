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
struct Project {
    int t, l, r, c;
    friend bool operator<(const Project &l, const Project&r) {
        return l.t + l.l < r.l + r.t;
    }
};
struct Node {
    // pref -> prefmin
    // suff -> suffmin
    // dynamic prefix/suffix
    set<pair<int, ll>> pref, suff;
    Node *l = NULL, *r = NULL;
};
const ll inf = 5e18;
const ll inf_half = inf / 2;
struct DynamicSegmentTree {
    Node *head = new Node();
    int lb, rb;
    DynamicSegmentTree(int leftBound, int rightBound) {
        lb = leftBound, rb = rightBound;
    }
    void update_pref(Node *nd, int cl, int cr, int idx, int val, int t) {
        assert(nd);
        // insertion code
        // pref
        // if there doesn't exist a left that is smaller than cur
        //cout << cl << " " << cr << endl;
        //cout << "PREF" << endl;
        //cout.flush();
        if(nd->pref.lb(mp(t, val)) == nd->pref.begin() || (*--nd->pref.lb(mp(t, val))).se > val) {
            // try delete the right of cur
            // if there exists a duplicate t the larger one will automatically be erased
            while(nd->pref.ub(mp(t, val)) != nd->pref.end() && (*nd->pref.ub(mp(t, val))).se >= val) {
                nd->pref.erase(nd->pref.ub(mp(t, val)));
            }
            nd->pref.insert(mp(t, val));
        }
        if(cl >= cr) {
            return;
        }
        else {
            int mid = (0ll + cl + cr) / 2;
            if(mid == cr)
                --mid;
            if(mid + 1 == cl)
                ++mid;
            if(idx <= mid) {
                if(!nd->l) {
                    nd->l = new Node();
                }
                update_pref(nd->l, cl, mid, idx, val, t);
            }
            else {
                if(!nd->r) {
                    nd->r = new Node();
                }
                update_pref(nd->r, mid + 1, cr, idx, val, t);
            }
        }
    }
    void update_suff(Node *nd, int cl, int cr, int idx, int val, int t) {
        assert(nd);
        // insertion code
        // suff
        // if there doesn't exist a right that is smaller than cur
        //cout << "SUFF" << endl;
        //cout.flush();
        if(nd->suff.lb(mp(t, val)) == nd->suff.end() || (*nd->suff.lb(mp(t, val))).se > val) {
            // try delete the left of cur
            // if there exists a duplicate t it should be fine (it should always go to the closest anyway)
            // if previous was larger, it would be deleted
            while(nd->suff.lb(mp(t, val)) != nd->suff.begin() && ((*--nd->suff.lb(mp(t, val))).se >= val)) {
                nd->suff.erase(--nd->suff.lb(mp(t, val)));
            }
            nd->suff.insert(mp(t, val));
        }
        if(cl >= cr) {
            return;
        }
        else {
            int mid = (0ll + cl + cr) / 2;
            if(mid == cr)
                --mid;
            if(mid + 1 == cl)
                ++mid;
            if(idx <= mid) {
                if(!nd->l) {
                    nd->l = new Node();
                }
                update_suff(nd->l, cl, mid, idx, val, t);
            }
            else {
                if(!nd->r) {
                    nd->r = new Node();
                }
                update_suff(nd->r, mid + 1, cr, idx, val, t);
            }
        }
    }
    ll query_suff(Node *nd, int cl, int cr, int l, int r, int t) {
        assert(nd);
        //cout << "QUERY SUFF " << cl << " " << cr << " " << l << " " << r << endl;
        //cout.flush();
        if(cl >= l && cr <= r) {
            // return query
            if(nd->suff.lb(mp(t, 0)) != nd->suff.end())
                return (*nd->suff.lb(mp(t, 0))).se;
            else
                return 1e14 + 5;
        }
        else if(cl >= cr || cl > r || cr < l) {
            return 1e14 + 5;
        }
        else {
            int mid = (0ll + cl + cr) / 2;
            if(mid == cr)   
                --mid;
            if(mid + 1 == cl)
                ++mid;
            ll ret = 5e18;
            if(nd->l) {
                ret = min(ret, query_suff(nd->l, cl, mid, l, r, t));
            }
            if(nd->r) {
                ret = min(ret, query_suff(nd->r, mid + 1, cr, l, r, t));
            }
            return ret;
        }
    }
    ll query_pref(Node *nd, int cl, int cr, int l, int r, int t) {
        assert(nd);
        //cout << "QUERY PREF " << cl << " " << cr << " " << l << " " << r << endl;
        //cout.flush();
        if(cl >= l && cr <= r) {
            // return query
            if(nd->pref.ub(mp(t, (ll)5e18)) != nd->pref.begin())
                return (*--nd->pref.ub(mp(t, (ll)5e18))).se;
            else
                return 1e14 + 5;
        }
        else if(cl >= cr || cl > r || cr < l) {
            return 1e14 + 5;
        }
        else {
            int mid = (0ll + cl + cr) / 2;
            if(mid == cr)
                --mid;
            if(mid + 1 == cl)
                ++mid;
            ll ret = 5e18;
            if(nd->l) {
                ret = min(ret, query_pref(nd->l, cl, mid, l, r, t));
            }
            if(nd->r) {
                ret = min(ret, query_pref(nd->r, mid + 1, cr, l, r, t));
            }
            return ret;
        }
    }
    void update_suff(int idx, int val, int t) {
        update_suff(head, lb, rb, idx, val, t);
    }
    void update_pref(int idx, int val, int t) {
        update_pref(head, lb, rb, idx, val, t);
    }
    ll query_suff(int l, int r, int t) {
        return query_suff(head, lb, rb, l, r, t);
    }
    ll query_pref(int l, int r, int t) {
        return query_pref(head, lb, rb, l, r, t);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    Project a[m + 1];
    for(int i = 1; i <= m; ++i) {
        cin >> a[i].t >> a[i].l >> a[i].r >> a[i].c;
    }
    sort(a + 1, a + m + 1);
    DynamicSegmentTree seg(-1e9, 2e9);
    ll res = 1e18;
    for(int i = 1; i <= m; ++i) {
        //cout << "NUMBER " << i << endl;
        //cout.flush();
        if(a[i].l == 1) {
            //cout << "HERE" << endl;
            seg.update_suff(a[i].r - a[i].t, a[i].c, a[i].t);
            seg.update_pref(a[i].r + a[i].t, a[i].c, a[i].t);
            //cout << "INIT COST " << a[i].c << endl;
            if(a[i].r == n)
                res = min(res, (ll)a[i].c);
        }
        else {
            // get from seg.query
            ll cur_res = min(seg.query_pref(a[i].l + a[i].t - 1, 2e9, a[i].t), seg.query_suff(a[i].l - a[i].t - 1, 2e9, a[i].t)) + a[i].c;
            cout << "DEBUG " << a[i].l << " " << a[i].r << " " << a[i].t << " " << cur_res << endl;
            //cout << "PREVIOUS RES " << min(seg.query_pref(a[i].l + a[i].t, 2e9, a[i].t), seg.query_suff(a[i].l - a[i].t, 2e9, a[i].t)) << endl;
            seg.update_suff(a[i].r - a[i].t, cur_res, a[i].t);
            seg.update_pref(a[i].r + a[i].t, cur_res, a[i].t);
            if(a[i].r == n)
                res = min(res, cur_res);
        }   
    }
    if(res > 1e14)
        cout << -1 << endl;
    else
        cout << res << endl;
    return 0;
}