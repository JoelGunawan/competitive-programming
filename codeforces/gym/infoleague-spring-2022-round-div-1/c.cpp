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
    ll val = 1;
    int l = -1, r = -1;
};
int mod = 1e9 + 7;
struct segtree {
    vector<node> a = {node()};
    ll lim = 2e9;
    void update(ll idx, ll val) {
        //cout << idx << " " << val << endl;
        idx += 1e9;
        update(0, 0, lim, idx, val);
    }
    void update(int nd, ll cl, ll cr, ll idx, ll val) {
        //cout << nd << " " << cl << " " << cr << endl;
        if(cl == cr) {
            a[nd].val += val;
        }
        else {
            int mid = (cl + cr) / 2;
            //cout << mid << endl;
            if(idx <= mid) {
                // upd left
                if(a[nd].l == -1)
                    a[nd].l = a.size(), a.pb(node());
                update(a[nd].l, cl, mid, idx, val);
                a[nd].val = a[a[nd].l].val;
                if(a[nd].r != -1)
                    a[nd].val *= a[a[nd].r].val;
            }
            else {
                // upd right
                if(a[nd].r == -1)
                    a[nd].r = a.size(), a.pb(node());
                update(a[nd].r, mid + 1, cr, idx, val);
                a[nd].val = a[a[nd].r].val;
                if(a[nd].l != -1)
                    a[nd].val *= a[a[nd].l].val;
            }
            a[nd].val %= mod;
        }
        //cout << nd << " " << a[nd].val << endl;
    }
    ll query(ll l, ll r) {
        l += 1e9, r += 1e9;
        return query(0, 0, lim, l, r);
    }
    ll query(int nd, ll cl, ll cr, ll l, ll r) {
        if(cl >= l && cr <= r) {
            //cout << "O " << nd << " " << cl << " " << cr << " " << a[nd].val << endl;
            return a[nd].val;
        }
        else if(cl > r || cr < l)   
            return 1;
        else {
            int mid = (cl + cr) / 2;
            ll tmp1 = 1, tmp2 = 1;
            if(a[nd].l != -1)
                tmp1 = query(a[nd].l, cl, mid, l, r);
            if(a[nd].r != -1)
                tmp2 = query(a[nd].r, mid + 1, cr, l, r);
            //cout << cl << " " << cr << " " << (tmp1 * tmp2) << endl;
            return (tmp1 * tmp2) % mod;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    map<pair<int, int>, bool> a;
    segtree seg;
    int x[n], y[n];
    for(int i = 0; i < n; ++i)
        cin >> x[i];
    for(int i = 0; i < n; ++i)
        cin >> y[i];
    for(int i = 0; i < n; ++i)
        a[mp(x[i], y[i])] = 1, seg.update(x[i], 1);
    //cout << "TEST" << endl;
    for(int i = 0; i < q; ++i) {
        char query;
        cin >> query;
        if(query == '!') {
            int x, y;
            cin >> x >> y;
            if(a[mp(x, y)])
                seg.update(x, -1);
            else
                seg.update(x, 1);
            a[mp(x, y)] = !a[mp(x, y)];
        }
        else {
            pair<int, int> a, b;
            cin >> a.fi >> a.se >> b.fi >> b.se;
            if(a == b || a.fi + 1 == b.fi)
                cout << 1 << endl;
            else if(a.fi >= b.fi)
                cout << 0 << endl;
            else
                cout << seg.query(a.fi + 1, b.fi - 1) << endl;
        }
    }
    return 0;
}