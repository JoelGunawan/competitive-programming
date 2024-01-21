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
const int lim = 1e5 + 5;
bool vis[lim];
vector<int> edges[lim];
void dfs(int nd) {
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i])
            dfs(i);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    vector<int> v;
    for(int i = 1; i <= n; ++i) {
        if(!vis[i])
            dfs(i), v.pb(i);
    }
    cout << v.size() - 1 << endl;
    for(int i = 1; i < v.size(); ++i)
        cout << v[i - 1] << " " << v[i] << endl;
    return 0;
}