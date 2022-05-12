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
void solve() {
    ll x;
    cin >> x;
    for(ll i = 1; i <= 1e5; ++i) {
        // binser semua kemungkinan
        int l = 1, r = i, ans = -1;
        while(l <= r) {
            ll mid = (l + r) / 2;
            //cout << i << " " << mid << " " << i * i - (i / mid) * (i / mid) << endl;
            if(i * i - (i / mid) * (i / mid) == x) {
                ans = mid;
                break;
            }
            else if(i * i - (i / mid) * (i / mid) < x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        if(ans != -1) {
            cout << i << " " << ans << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}