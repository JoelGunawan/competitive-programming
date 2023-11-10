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
        int m, k, s, e;
        cin >> m >> k >> s >> e;
        // try to reduce by k
        m = max((ll)m % k, m - 1ll * e * k);
        // is reg enough?
        if(s >= m) {
            cout << 0 << endl;
            continue;
        }
        // how many k to add
        // add by k until it can fully be added by 1
        int res = 0;
        if(s <= m % k) {
            m -= s;
            res += m / k + m % k;
        }
        else {
            m -= s;
            res = m / k + (bool)(m % k);
        }
        cout << res << endl;
    }
    return 0;
}