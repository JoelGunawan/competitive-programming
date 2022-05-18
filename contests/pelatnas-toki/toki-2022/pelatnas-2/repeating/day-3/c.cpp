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
pair<int, int> points[2005];
int dp[2005];
pair<int, pair<int, int>> cur[4000005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> points[i].fi >> points[i].se;
        //cout << x << " " << y << endl;
    }
    int cur_size = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            cur[cur_size++] = mp(sqr(points[i].fi - points[j].fi) + sqr(points[i].se - points[j].se), mp(i, j));
        }
    }
    sort(cur, cur + cur_size);
    // do dp using sets
    // find from shortest distance
    // maintain set of shortest distance and
    int idx = 0;
    while(idx < cur_size) {
        int tmp = cur[idx].fi;
        vector<pair<int, int>> operations;
        while(idx < cur_size && cur[idx].fi == tmp) {
            if(cur[idx].se.se != n)
                operations.pb(mp(cur[idx].se.fi, dp[cur[idx].se.se] + 1));
            operations.pb(mp(cur[idx].se.se, dp[cur[idx].se.fi] + 1));
            ++idx;
        }
        for(auto i : operations)
            dp[i.fi] = max(dp[i.fi], i.se);
    }
    cout << dp[n] << endl;
    return 0;
}