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
const int lim = 3e5 + 5;
vector<int> edges[lim];
char ans[lim];
bool vis[lim];
void dfs(int nd) {
    vis[nd] = 1, ans[nd] = 'B';
    //cout << nd << " " << ans[nd] << endl;
    for(auto i : edges[nd])
        if(!vis[i])
            dfs(i);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    vis[n] = 1;
    dfs(n - 1);
    for(int i = 1; i <= n; ++i)
        if(ans[i] != 0)
            cout << ans[i];
        else
            cout << 'A';
    cout << endl;
    return 0;
}