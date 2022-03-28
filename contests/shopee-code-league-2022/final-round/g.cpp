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
int adj[305][305];
vector<int> edges[305];
bool vis[305];
int dfs(int nd) {
    vis[nd] = 1;
    int res = 1;
    for(auto i : edges[nd]) {
        if(!vis[i])
            res += dfs(i);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) {
            cin >> adj[i][j];
            if(adj[i][j])
                edges[i].pb(j);
        }
    int num;
    set<pair<int, int>> ans;
    while(cin >> num) {
        memset(vis, 0, sizeof(vis));
        ans.ins(mp(dfs(num), num));
    }
    cout << (*ans.begin()).se << endl;
    return 0;
}