// header file
#include <bits/stdc++.h>
// pragma
// macros
#define endl "\n"
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
#define sqr(a) (a) * (a)
using namespace std;
pair<int, int> edges[2005][2005];
int last[2005];
pair<int, int> points[2005];
int dp[2005][2005];
pair<int, pair<int, int>> cur[4000005];
int previous[2005];
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> points[i].fi >> points[i].se;
        //cout << x << " " << y << endl;
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            //cout << points[i].fi << " " << points[i].se << " " << points[j].fi << " " << points[j].se << " " << i << " " << j << endl;
            edges[i][j - 1] = (mp(sqr(points[i].fi - points[j].fi) + sqr(points[i].se - points[j].se), j));
            edges[j][i] = (mp(sqr(points[i].fi - points[j].fi) + sqr(points[i].se - points[j].se), i));
        }
    }
    for(int i = 0; i < n; i++)
        sort(edges[i], edges[i] + n - 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++)
            cur[i * (n - 1) + j] = mp(edges[i][j].fi, mp(i, j));
    }
    sort(cur, cur + n * (n - 1));
    memset(previous, -1, sizeof(previous));
    // do dp using sets
    // find from shortest distance
    // maintain set of shortest distance and
    for(int i = 0; i < n * (n - 1); i++) {
        int &nd = cur[i].se.fi, idx = cur[i].se.se, &dist = cur[i].fi, &target_nd = edges[nd][idx].se;
        // largest smaller than value
        for(int i = previous[target_nd] + 1; edges[target_nd][previous[target_nd] + 1].fi < dist && i < n - 1; i++) {
            previous[target_nd] = i;
        }
        //int target_idx = lower_bound(edges[target_nd].begin(), edges[target_nd].end(), mp(dist, 0)) - edges[target_nd].begin() - 1;
        //cout << nd << " " << target_idx << endl;
        //cout << dist << " " << nd << " " << idx << " " << target_nd << " " << target_idx << endl;
        if(idx != 0)
            dp[nd][idx] = dp[nd][idx - 1];
        if(previous[target_nd] == -1)
            dp[nd][idx] = max(dp[nd][idx], 1);
        else
            dp[nd][idx] = max(dp[nd][idx], dp[target_nd][previous[target_nd]] + 1);
        //cout << nd << " " << idx << " " << target_nd << " " << target_idx << " " << dp[nd][idx] << endl;
    }
    int res = 1;
    for(int i = 0; i < n; i++) {
        // go to the ith node
        int &target_nd = i;
        int target_idx = lower_bound(edges[target_nd], edges[target_nd] + n - 1, mp(sqr(points[i].fi) + sqr(points[i].se), 0)) - edges[target_nd] - 1;
        if(target_idx >= 0)
            res = max(res, dp[target_nd][target_idx]);
    }
    ++res;
    printf("%d\n", res);
    return 0;
}