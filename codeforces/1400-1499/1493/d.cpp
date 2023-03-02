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
const int lim = 1 << 18;
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
struct node {
    set<pair<int, int>> s;
    int lchild = -1, rchild = -1, par = -1;
};
struct segment_tree {
    ll total_res = 1;
    int size;
    vector<node> a = {node()};
    void update(int num, set<pair<int, int>> upd) {
        //cout << "TEST" << endl;
        set<pair<int, int>> tmp = upd;
        int l = 1, r = size;
        int nd = 0, pr, other;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(num <= mid) {
                if(a[nd].lchild == -1) {
                    a.pb(node());
                    a.back().par = nd;
                    a[nd].lchild = a.size() - 1;
                }
                nd = a[nd].lchild;
                r = mid;
            }
            else {
                if(a[nd].rchild == -1) {
                    a.pb(node());
                    a.back().par = nd;
                    a[nd].rchild = a.size() - 1;
                }
                nd = a[nd].rchild;
                l = mid + 1;
            }
        }
        //cout << "TEST2" << endl;
        pr = nd;
        nd = a[nd].par;
        bool other_ext = a[nd].lchild != -1 && a[nd].rchild != -1;
        while(nd != -1) {
            bool other_ext = a[nd].lchild != -1 && a[nd].rchild != -1;
            if(a[nd].lchild == pr)
                other = a[nd].rchild;
            else
                other = a[nd].lchild;
            upd.clear();
            //cout << "TST" << endl;
            for(auto i : tmp) {
                //cout << a[nd].par << " " << nd << " " << pr << " " << other << endl;
                if(other_ext && a[other].s.lb(mp(i.fi, 0)) != a[other].s.end() && (*a[other].s.lb(mp(i.fi, 0))).fi == i.fi) {
                    pair<int, int> tmp = mp(i.fi, (*a[other].s.lb(mp(i.fi, 0))).se);
                    a[other].s.erase(a[other].s.lb(mp(i.fi, 0)));
                    if(i.se > tmp.se) {
                        upd.ins(tmp);
                        a[pr].s.ins(mp(i.fi, i.se - tmp.se));
                        //cout << "UPDS " << pr << " " << i.fi << " " << i.se - tmp.se << endl;
                    }
                    else if(i.se == tmp.se) {
                        upd.ins(i);
                    }
                    else {
                        upd.ins(i);
                        a[other].s.ins(mp(i.fi, tmp.se - i.se));                   
                        //cout << "UPD " << other << " " << i.fi << " " << tmp.se - i.se << endl;
                    }
                }
                else {
                    //cout << "UPDT " << pr << " " << i.fi << " " << i.se << endl;
                    if((a[pr].s.lb(mp(i.fi, 0)) != a[pr].s.end() && (*a[pr].s.lb(mp(i.fi, 0))).fi == i.fi)) {
                        a[pr].s.ins(mp(i.fi, i.se + (*a[pr].s.lb(mp(i.fi, 0))).se));
                        a[pr].s.erase(a[pr].s.lb(mp(i.fi, 0)));
                    }
                    else
                        a[pr].s.ins(i);
                }
            }
            tmp = upd;
            pr = nd;
            nd = a[nd].par;
        }
        //out << "OUTPUT" << endl;
        for(auto i : tmp) {
            //cout << i.fi << " " << i.se << endl;
            total_res *= powmod(i.fi, i.se);
            total_res %= mod;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    segment_tree segtree;
    int n, q;
    cin >> n >> q;
    segtree.size = n;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        set<pair<int, int>> s;
        //cout << "TEST2" << endl;
        for(int j = 2; j <= sqrt(x); ++j) {
            if(x % j == 0) {
                int cnt = 0;
                while(x % j == 0) {
                    ++cnt;
                    x /= j;
                }
                s.ins(mp(j, cnt));
            }
        }
        //cout << "TEST3" << endl;
        if(x > 1)
            s.ins(mp(x, 1));
        if(s.size())
            segtree.update(i, s);
    }
    for(int i = 0; i < q; ++i) {
        int idx, x;
        cin >> idx >> x;
        set<pair<int, int>> s;
        for(int j = 2; j <= sqrt(x); ++j) {
            if(x % j == 0) {
                int cnt = 0;
                while(x % j == 0) {
                    ++cnt;
                    x /= j;
                }
                s.ins(mp(j, cnt));
            }
        }
        //cout << "TEST4" << endl;
        if(x > 1)
            s.ins(mp(x, 1));
        if(s.size())
            segtree.update(idx, s);
        cout << segtree.total_res << endl;
    }
    return 0;
}