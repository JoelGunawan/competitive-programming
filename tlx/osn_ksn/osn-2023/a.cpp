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
const int lim = 1 << 18;
struct lazy_segment_tree {
    long long a[2 * lim], lazy[2 * lim], inf = 1e18;
    lazy_segment_tree() {
        memset(a, 0, sizeof(a));
        memset(lazy, 0, sizeof(lazy));
    }
    int arr_size = lim;
    void propagate(int nd, int cl, int cr) {
        a[nd] = max(a[nd], lazy[nd]);
        if(cl != cr) {
            lazy[2 * nd] = max(lazy[2 * nd], lazy[nd]);
            lazy[2 * nd + 1] = max(lazy[2 * nd + 1], lazy[nd]);
        }
        lazy[nd] = 0;
    }
    void update(int l, int r, long long val) {
        update(1, 0, arr_size - 1, l, r, val);
    }
    void update(int nd, int cl, int cr, int l, int r, long long val) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            lazy[nd] = max(lazy[nd], val);
            propagate(nd, cl, cr);
        }
        else if(cl > r || cr < l) {
            return;
        }
        else {
            int mid = (cl + cr) / 2;
            update(2 * nd, cl, mid, l, r, val);
            update(2 * nd + 1, mid + 1, cr, l, r, val);
            a[nd] = max(a[2 * nd], a[2 * nd + 1]);
        }
    }
    long long query(int nd, int cl, int cr, int l, int r) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l) 
            return -inf;
        else {
            int mid = (cl + cr) / 2;
            return max(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
    long long query(int l, int r) {
        return query(1, 0, lim - 1, l, r);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    lazy_segment_tree seg;
    seg.update(0, n, 0);
    // operasi 1 -> pakai pos
    // operasi 2 -> kembali ke 1, berarti nnti pos[n - i], pos[n - i - 1], pos[n - i - 2], ... diganti jadi curp
    for(int i = 1; i <= n; ++i) {
        // pos - time + N
        // a[i] - i + N
        int curp = a[i] - i + n;
        //cout << curp << " " << pos[curp] << endl;
        if(a[i] <= i) {
            seg.update(curp, curp, seg.query(curp, curp) + 1);
            // pergi ke waktu ke i
            // tiap ke kanan ada 2 pilihan, kembali ke 1 atau kembali ke 
            seg.update(0, n - i, seg.query(curp, curp));
        }
        // coba maximize dr zero
    }
    // 1 - (i + 1) + n
    //for(int i = 1; i <= 2 * n; ++i)
    //    cout << pos[i] << " ";
    //cout << endl;
    cout << n - seg.query(0, n) << endl;
    return 0;
}