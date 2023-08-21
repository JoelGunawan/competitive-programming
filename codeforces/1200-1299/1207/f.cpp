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
const int lim = 1e6 + 5;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int q;
    cin >> q;
    // kalo sebuah idx lebih dr 500 query -> hitung manual
    // else hitung pake sqrt
    int blk = 700;
    int a[lim], b[blk + 1][blk + 1];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    // a -> elem val
    // b -> what remainder modulo for less than blk
    while(q--) {
        int t, x, y;
        cin >> t >> x >> y;
        // kurangi yg old dulu
        if(t == 1) {
            for(int i = 1; i <= 700; ++i) {
                b[i][x % i] -= a[x];
            }
            a[x] += y;
            for(int i = 1; i <= 700; ++i) {
                b[i][x % i] += a[x];
            }
        }
        else {
            // mod x hasil y
            ll res = 0;
            if(x <= 700) {
                res = b[x][y];
            }
            else {
                for(int i = y; i <= 5e5; i += x) {
                    res += a[i];
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}