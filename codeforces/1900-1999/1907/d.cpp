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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // bsta
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        pair<int, int> a[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> a[i].fi >> a[i].se;
        int l = 0, r = 1e9, ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            int cl = 0, cr = 0;
            bool valid = 1;
            for(int i = 1; i <= n; ++i) {
                if(a[i].fi < cl)
                    cl = max(a[i].fi, cl - mid);
                else
                    cl = min(a[i].fi, cl + mid);
                if(a[i].se < cr)
                    cr = max(a[i].se, cr - mid);
                else
                    cr = min(a[i].se, cr + mid);
                if(cl > a[i].se || cr < a[i].fi)
                    valid = 0;
                if(cl < a[i].fi)
                    cl = a[i].fi;
                if(cr > a[i].se)
                    cr = a[i].se;
            }
            if(valid) 
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}