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
    int val = 0, l = -1, r = -1;
};
struct segtree {
    vector<node> a = {node()};
    int arr_size = 1e9 + 5;
    void update(int nd, int cl, int cr, int idx, int val) {
        a[nd].val += val;
        //cout << "UPD " << nd << " " << a[nd].val << endl;
        if(cl != cr) {
            int mid = (cl + cr) / 2;       
            if(idx <= mid) {
                // update left
                if(a[nd].l == -1) {
                    a[nd].l = a.size(), a.pb(node());
                }
                update(a[nd].l, cl, mid, idx, val);
            }
            else {
                // update right
                if(a[nd].r == -1) {
                    a[nd].r = a.size(), a.pb(node());
                }
                update(a[nd].r, mid + 1, cr, idx, val);
            }
        }
    }
    int query(int nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r) {
            //cout << "Q " << nd << " " << a[nd].val << endl;
            return a[nd].val;
        }
        else if(cl > r || cr < l)
            return 0;
        else {
            int mid = (cl + cr) / 2;
            int res = 0;
            if(a[nd].l != -1)
                res += query(a[nd].l, cl, mid, l, r);
            if(a[nd].r != -1) 
                res += query(a[nd].r, mid + 1, cr, l, r);
            return res; 
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    int p[n + 1];
    segtree seg;
    for(int i = 1; i <= n; ++i)
        cin >> p[i], seg.update(0, 0, seg.arr_size, p[i], 1);
    for(int i = 0; i < q; ++i) {
        char q;
        cin >> q;
        if(q == '!') {
            int k, x;
            cin >> k >> x;
            seg.update(0, 0, seg.arr_size, p[k], -1);
            p[k] = x;
            seg.update(0, 0, seg.arr_size, p[k], 1);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << seg.query(0, 0, seg.arr_size, a, b) << endl;
        }
    }
    return 0;
}