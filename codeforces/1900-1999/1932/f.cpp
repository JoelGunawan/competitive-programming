// header file
#include <bits/stdc++.h>
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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int diff[n + 2];
        memset(diff, 0, sizeof(diff));
        int minl[n + 1], cnt[n + 1];
        pair<int, int> a[m + 1];
        for(int i = 1; i <= m; ++i) 
            cin >> a[i].fi >> a[i].se;
        for(int i = 1; i <= m; ++i) {
            diff[a[i].fi] += 1;
            diff[a[i].se + 1] -= 1;
        }
        int cur = 0;
        for(int i = 1; i <= n; ++i) {
            cur += diff[i];
            cnt[i] = cur;
        }
        // have cnt, now do minl
        multiset<int> s;
        vector<pair<int, bool>> v[n + 1];
        for(int i = 1; i <= m; ++i) {
            v[a[i].fi].pb(mp(a[i].fi, 0));
            v[a[i].se].pb(mp(a[i].fi, 1));
        }
        for(int i = 1; i <= n; ++i) {
            sort(v[i].begin(), v[i].end());
            minl[i] = s.size() ? *s.begin() : i;
            for(auto p : v[i]) {
                if(p.se) {
                    // remove
                    s.erase(s.lb(p.fi));
                }
                else {
                    // insert
                    s.ins(p.fi);
                }
            }
            if(s.size())
                minl[i] = min(minl[i], *s.begin());
        }
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            dp[i] = max(dp[i], dp[minl[i] - 1] + cnt[i]);
        }
        cout << dp[n] << endl;
    }
    return 0;
}