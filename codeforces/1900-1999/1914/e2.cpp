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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n + 1], b[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        for(int i = 1; i <= n; ++i)
            cin >> b[i];
        pair<int, pair<int, int>> c[n + 1];
        for(int i = 1; i <= n; ++i)
            c[i] = mp(a[i] + b[i], mp(a[i], b[i]));
        sort(c + 1, c + n + 1);
        reverse(c + 1, c + n + 1);
        ll res = 0;
        for(int i = 1; i <= n; ++i) {
            if(i & 1) {
                // alice
                res += c[i].se.fi - 1;
            }
            else {
                // bob
                res -= c[i].se.se - 1;
            }
        }
        cout << res << endl;
    }
    return 0;
}