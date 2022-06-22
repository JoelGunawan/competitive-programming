// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
// macros
#define endl "\n"
#define ll int
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
const int lim = 1 << 19;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    pair<int, bool> a[2 * n];
    for(int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        a[2 * i] = mp(l, 0);
        a[2 * i + 1] = mp(r, 1);
    }
    sort(a, a + 2 * n);
    int q, x, y;
    cin >> q >> x >> y;
    int cnt = 0, res = 0;
    for(int i = 0; i < 2 * n; ++i) {
        if(a[i].se)
            --cnt;
        else
            ++cnt;
        res = max(res, cnt);
    }
    cout << res << endl;
    return 0;
}