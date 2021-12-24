// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
vector<int> edges[200001];
int par[200001], furthest_leaf[200001];
bool vis[200001];
int dfs(int node = 1) {
    vis[node] = 1;
    for(auto i : edges[node]) {
        par[i] = node;
        if(!vis[i])
            furthest_leaf[node] = max(furthest_leaf[node], dfs(i) + 1);
    }
    return furthest_leaf[node];
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dfs();
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    // fi dist to furthest leaf, se node
    vector<pair<int ,int>> a(n);
    for(int i = 1; i <= n; ++i) {
        a[i - 1] = mp(furthest_leaf[i], i);
    }
    cout << endl;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int removed = 0, red_cnt = k;
    for(int i = 0; i < n; ++i) {
        cout << a[i].fi << " " << a[i].se << endl;
        if(!vis[a[i].se] && k > 0) {
            removed += a[i].fi + 1;
            int tmp = a[i].se;
            while(!vis[tmp]) {
                vis[tmp] = 1;
                tmp = par[tmp];
            }
            --k;
        }
    }
    cout << (removed - red_cnt) * (red_cnt - (n - removed)) << endl;
    return 0;
}