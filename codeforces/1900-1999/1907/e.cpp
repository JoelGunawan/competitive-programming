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
    // dp[n][sum][used];
    // for given n = sum of numbers, sum = sum of digit, used = cnt of used in the triple (1, 2, 3)
    // n is at most 1e7
    // sum is at most 63
    // used is at most 3
    // ~1e9
    // MLE/TLE
    // memo[digsum][usedcnt]
    // observe:
    // at least one of them has to be >= n / 3
    // at least one of them has to be <= n / 3
    // possible configs: 2 low 1 high, 2 high 1 low
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        ll res = 1;
        for(auto i : s) {
            int x = i - '0';
            res *= 1ll * (x + 1) * (x + 2) / 2;
        }
        cout << res << endl;
    }
    return 0;
}