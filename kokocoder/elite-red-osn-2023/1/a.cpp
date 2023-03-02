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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int l = 1, r = n, ans = 1;
        pair<int, int> a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i].fi >> a[i].se, swap(a[i].fi, a[i].se);
        while(l <= r) {
            int mid = (l + r) >> 1, cur_cnt = 0;
            for(int i = 0; i < n; ++i) {
                if(a[i].se >= mid - cur_cnt - 1 && a[i].fi >= cur_cnt)
                    ++cur_cnt;
            }
            if(cur_cnt >= mid)
                l = mid + 1, ans = mid;
            else
                r = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}