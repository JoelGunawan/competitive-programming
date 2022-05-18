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
const int lim = 1e5 + 5;
struct bit {
    int a[lim];
    bit() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        while(idx < lim) {
            a[idx] += val;
            idx += (idx&-idx);
        }
    }
    int query(int idx) {
        int res = 0;
        while(idx > 0) {
            res += a[idx];
            idx -=(idx&-idx);
        }
        return res;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    bit bit;
    for(int i = 1; i <= n; ++i)
        bit.update(i, 1);
    // kalo x > cur / 2
    // kita anggep flipnya kebalik (supaya calcnya lebih pendek)
    // jadi kita g ush reverse
    // pindah active range
    bool reverse = 0;
    int l = 1, r = n;
    for(int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if(t == 1) {
            int x;
            cin >> x;
            if(x <= (r - l + 1) / 2) {
                if(reverse) {
                    for(int i = 1; i <= x; ++i)
                        bit.update(r - x - i + 1, bit.query(r - x + i, r - x + i));
                    r -= x;
                }
                else {
                    for(int i = 1; i <= x; ++i)
                        bit.update(l + x + i - 1, bit.query(l + x - i, l + x - i));
                    l += x;
                }
            }
            else {
                int tmp = (r - l + 1) - x;
                if(!reverse) {
                    for(int i = 1; i <= tmp; ++i)
                        bit.update(r - tmp - i + 1, bit.query(r - tmp + i, r - tmp + i));
                    r -= tmp;
                }
                else {
                    for(int i = 1; i <= tmp; ++i)
                        bit.update(l + tmp + i - 1, bit.query(l + tmp - i, l + tmp - i));
                    l += tmp;
                }
                reverse = !reverse;
            }
        }
        else {
            int ql, qr;
            cin >> ql >> qr;
            if(reverse)
                cout << bit.query(r - qr + 1, r - ql + 1) << endl;
            else
                cout << bit.query(l + ql - 1, l + qr - 1) << endl;
        }
    }
    return 0;
}