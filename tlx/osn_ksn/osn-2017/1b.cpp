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
    string buang;
    cin >> buang;
    int n;
    ll lim;
    cin >> n >> lim;
    string t, s;
    cin >> t >> s;
    int p[t.size() + 1], ball_cnt = 0, one_cnt = 0;
    for(int i = 0; i < t.size(); ++i)
        p[i + 1] = t[i] - '0', one_cnt += s[i] - '0', ball_cnt += p[i + 1];
    vector<int> one_loc;
    one_loc.pb(0);
    for(int i = 0; i < s.size(); ++i)
        if(s[i] == '1')
            one_loc.pb(i + 1);
    int dp[2][ball_cnt + 1][one_cnt + 1];
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    int res = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= ball_cnt; ++j) {
            int pr = -1;
            for(int k = 0; k <= one_cnt; ++k) {
                dp[i & 1][j][k] = dp[(i & 1) ^ 1][j][k];
                if(pr != -1) {
                    if(dp[i & 1][j][k] == -1)
                        dp[i & 1][j][k] = pr + abs(i - one_loc[k]);
                    else
                        dp[i & 1][j][k] = min(dp[i & 1][j][k], pr + abs(i - one_loc[k]));
                }
                if(j >= p[i]) {
                    if(pr == -1)
                        pr = dp[(i & 1) ^ 1][j - p[i]][k];
                    else if(dp[(i & 1) ^ 1][j - p[i]][k] != -1)
                        pr = min(pr, dp[(i & 1) ^ 1][j - p[i]][k]);
                }
                if(dp[i & 1][j][k] <= lim && dp[i & 1][j][k] != -1)
                    res = max(res, j);
            }
        }
    }
    cout << res << endl;
    return 0;
}