#include <bits/stdc++.h>
using namespace std;
const int lim = 1e6 + 5;
int a[lim], dp[lim];
bool vis[lim];
vector<int> edges[lim];
int dfs(int nd) {
    vis[nd] = 1;
    dp[nd] = a[nd];
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            dp[nd] = max(dp[nd], dfs(i) + a[nd]);
        }
    }
    return dp[nd];
}
int main() {
    int n, ns, p0;
    cin >> n >> ns >> p0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, string>> awal_dfs;
    for(int i = 0; i < p0; ++i) {
        string s;
        int k;
        cin >> s >> k;
        awal_dfs.push_back(make_pair(k, s));
    }
    for(int i = 0; i < n - p0; ++i) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
    }
    int mx = 0; string ans;
    for(auto x : awal_dfs) {
        int cur = dfs(x.first);
        if(cur > mx) {
            mx = cur;
            ans = x.second;
        }
    }
    cout << ans << endl << mx << endl;
}