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
const int lim = 200001;
vector<pair<int, int>> edges[lim];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> adj(n - 1);
    for(int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].pb(mp(b, c));
        edges[b].pb(mp(a, c));
        adj[i] = (mp(c, mp(a, b)));
    }
    sort(adj.begin(), adj.end());
    ll res = 0;
    ll dp[n + 1], dp_last[n + 1];
    for(int i = 0; i <= n; ++i)
        dp[i] = 1;
    int last[n + 1];
    memset(dp_last, 0, sizeof(dp_last));
    memset(last, 0, sizeof(last));
    for(auto i : adj) {
        int cur = i.fi;
        int l = i.se.fi, r = i.se.se;
        ll l_new = 0, r_new = 0;
        l_new = dp[r], r_new = dp[l];
        if(last[r] != cur) {
            l_new += dp_last[r];
            dp[r] += dp_last[r];
            dp_last[r] = 0;
        }
        if(last[l] != cur) {
            r_new += dp_last[l];
            dp[l] += dp_last[l];
            dp_last[l] = 0;
        }
        last[l] = cur;
        last[r] = cur;
        dp_last[l] += l_new, dp_last[r] += r_new;
    }
    for(int i = 1; i <= n; ++i)
        res += dp[i] + dp_last[i];
    cout << res - n << endl;
    return 0;
}