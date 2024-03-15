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
void tc() {
    int x;
    cin >> x;
    for(int i = 1; i <= 1e5; ++i) {
        int l = 1, r = i;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(1ll * i * i - (i / mid) * (i / mid) == x) {
                cout << i << " " << mid << endl;
                return;
            }
            else if(1ll * i * i - (i / mid) * (i / mid) > x) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
    }
    cout << -1 << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}