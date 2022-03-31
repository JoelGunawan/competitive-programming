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
            a[idx] = max(a[2 * idx], a[2 * idx + 1]);
        }
    }
    int query(int nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l)
            return 0;
        else {
            int mid = (cl + cr) / 2;
            return max(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
    int query(int l, int r) {
        return query(1, 0, arr_size - 1, l, r);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    segtree seg;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        seg.update(i + 1, x);
    }
    for(int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        // binser
        int l = 1, r = n, ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(seg.query(1, mid) >= x) {
                ans = mid, r = mid - 1;
            }
            else
                l = mid + 1;
        }
        if(ans != 0) {
            seg.update(ans, seg.a[ans + seg.arr_size] - x);
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}