// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int lim = 1e6 + 5;
struct fenwick {
    int a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void upd(int idx, int val) {
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    int q(int idx) {
        int res = 0;
        while(idx) {
            res += a[idx];
            idx -= idx&-idx;
        }
        return res;
    }
    int q(int l, int r) {
        return q(r) - q(l - 1);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    fenwick bit;
    for(int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if(a == x)
            bit.upd(i, 1);
    }
    int q;
    cin >> q;
    for(;q--;) {
        int t;
        cin >> t;
        if(t == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            if(bit.q(l, r) < k) {
                cout << -1 << endl;
                continue;
            }
            int left = l, right = r, ans;
            while(left <= right) {
                int mid = (left + right) >> 1;
                if(bit.q(l, mid) >= k)
                    right = mid - 1, ans = mid;
                else
                    left = mid + 1;
            }
            cout << ans << endl;
        }
        else {
            int idx, v;
            cin >> idx >> v;
            if(v != x && bit.q(idx, idx) == 1)
                bit.upd(idx, -1);
            if(v == x && bit.q(idx, idx) == 0)
                bit.upd(idx, 1);
        }
    }
    return 0;
}