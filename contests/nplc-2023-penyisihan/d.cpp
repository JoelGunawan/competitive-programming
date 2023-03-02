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
    // string algo n^2 yg ada di cp handbook bab string??
    // dp[s1.size()][s2.size()]
    string s, t;
    getline(cin, s);
    getline(cin, t);
    if(s.size() == 0 || t.size() == 0) {
        cout << max(s.size(), t.size()) << endl;
        return 0;
    }
    s = " " + s, t = " " + t;
    int dp[s.size()][t.size()];
    int n = s.size() - 1, m = t.size() - 1;
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= m; ++j)
            dp[i][j] = 1e9;
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i)
        dp[i][0] = i;
    for(int i = 1; i <= m; ++i)
        dp[0][i] = i;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
            if(s[i] == t[j])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    cout << dp[n][m] << endl;
    return 0;
}