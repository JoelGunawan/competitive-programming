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
bool precalc[1001][1001];
vector<int> edges[1001];
int subtree[1001];
bool vis[1001];
int dfs(int nd) {
    vis[nd] = 1;
    subtree[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i])
            subtree[nd] += dfs(i);
    }
    return subtree[nd];
}
void tc() {
    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; ++i)
        edges[i].clear();
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    memset(subtree, 0, sizeof(subtree));
    memset(vis, 0, sizeof(vis));
    dfs(1);
    if(edges[x].size() <= 1)
        cout << "Ayush" << endl;
    else {
        if(n & 1)
            cout << "Ashish" << endl;
        else
            cout << "Ayush" << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
    int t;
    cin >> t;
    memset(precalc, 0, sizeof(precalc));
    for(int i = 0; i <= 1000; ++i) {
        precalc[i][0] = 1;
        precalc[0][i] = 1;
    }
    for(int i = 1; i <= 1000; ++i) {
        for(int j = 1; j <= 1000; ++j) {
            precalc[i][j] = !precalc[i - 1][j] | !precalc[i][j - 1];
        }
    }
    while(t--) {
        tc();
    }
    return 0;
}