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
const int lim = 1 << 17;
struct segment_tree {
    int a[2 * lim];
    segment_tree() {
        memset(a, 0, sizeof(a));
    }
    void upd(int idx, int val) {
        idx += lim;
        a[idx] = val;
        while(idx) {
            idx >>= 1;
            a[idx] = max(a[2 * idx], a[2 * idx + 1]);
        }
    }
    int query(int nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r)
            return a[nd];
        else if(cl > r || cr < l)
            return 0;
        else {
            int mid = (cl + cr) >> 1;
            return max(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // pakai segtree biar gampang :3
    int n;
    cin >> n;
    int ans[n];
    pair<int, pair<int, int>> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi >> a[i].se.fi, a[i].se.se = i;
    sort(a, a + n);
    segment_tree seg;
    for(int i = n - 1; i >= 0; --i) {
        int l = i + 1, r = n - 1, pr = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(a[mid].fi - a[i].fi < a[i].se.fi)
                pr = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        if(pr == -1)
            ans[a[i].se.se] = 1, seg.upd(i, i);
        else {
            ans[a[i].se.se] = seg.query(1, 0, lim - 1, i + 1, pr) - i + 1;
            seg.upd(i, seg.query(1, 0, lim - 1, i + 1, pr));
        }
    }
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}