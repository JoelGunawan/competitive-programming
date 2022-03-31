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
const int lim = 1 << 18;
struct segtree {
    int a[2 * lim], arr_size = lim;
    segtree() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        idx += arr_size;
        a[idx] = val;
        while(idx > 1) {
            idx /= 2;
            a[idx] = a[2 * idx] + a[2 * idx + 1];
        }
    }
    int query(int nd, int cl, int cr, int val) {
        // find index of val-th number
        if(cl == cr)
            return cl;
        else {
            // go left or go right
            if(a[2 * nd] >= val) {
                // left
                return query(2 * nd, cl, (cl + cr) / 2, val);
            }
            else {
                // right
                val -= a[2 * nd];
                return query(2 * nd + 1, (cl + cr) / 2 + 1, cr, val);
            }
        }
    }

};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    segtree seg;
    for(int i = 1; i <= n; ++i)
        seg.update(i, 1);
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i) {
        int pos;
        cin >> pos;
        int idx = seg.query(1, 0, seg.arr_size - 1, pos);
        seg.update(idx, 0);
        cout << a[idx] << endl;
    }
    return 0;
}