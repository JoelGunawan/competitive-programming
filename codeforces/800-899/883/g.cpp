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
vector<int> forced_edges[300005];
vector<pair<int, pair<int, bool>>> edges[300005];
bool vis[300005], forced_vis[300005];
vector<char> ans, forced_ans;
int dfs(int nd) {
    vis[nd] = 1;
    int res = 1;
    for(auto i : edges[nd])
        if(!vis[i.fi]) {
            if(i.se.se) {
                ans[i.se.fi] = '-';
            }
            res += dfs(i.fi);
        }
    for(auto i : forced_edges[nd])
        if(!vis[i])
            res += dfs(i);
    return res;
}
int forced_dfs(int nd) {
    forced_vis[nd] = 1;
    int res = 1;
    for(auto i : forced_edges[nd])
        if(!forced_vis[i])
            res += forced_dfs(i);
    for(auto i : edges[nd]) {
        if(!i.se.se)
            forced_ans[i.se.fi] = '-';
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, s;
    cin >> n >> m >> s;
    int cnt = 0;
    for(int i = 0; i < m; ++i) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 1)
            forced_edges[u].pb(v);
        else
            edges[u].pb(mp(v, mp(cnt, 0))), edges[v].pb(mp(u, mp(cnt, 1))), ++cnt;
    }
    forced_ans = ans = vector<char>(cnt, '+');
    cout << dfs(s) << endl;
    for(auto i : ans)
        cout << i;
    cout << endl;
    cout << forced_dfs(s) << endl;
    for(auto i : forced_ans)
        cout << i;
    cout << endl;
    return 0;
}