// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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
void tc() {
    int n;
    cin >> n;
    vector<int> edges[n + 1];
    vector<pair<int, int>> memo(n - 1);
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
        memo[i] = mp(min(u, v), max(u, v));
    }
    // harus cari bipartite matching
    // :O
    // edge_cnt harus 1 atau 2 doang
    bool ans = 1;
    for(int i = 1; i <= n; ++i) {
        if(edges[i].size() > 2)
            ans = 0;
    }
    if(!ans) {
        cout << -1 << endl;
        return;
    }
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    vector<pair<int, int>> two, three;
    function<void(int, int)> dfs = [&] (int nd, int d) -> void {
        vis[nd] = 1;
        for(auto i : edges[nd]) {
            if(vis[i])
                continue;
            if(d & 1)
                two.pb(mp(min(i, nd), max(i, nd)));
            else
                three.pb(mp(min(i, nd), max(i, nd)));
            dfs(i, d + 1);
        }
    };
    for(int i = 1; i <= n; ++i) {
        if(edges[i].size() == 1) {
            dfs(i, 0);
            continue;
        }
    }
    sort(two.begin(), two.end());
    sort(three.begin(), three.end());
    for(int i = 0; i < memo.size(); ++i) {
        if(find(two.begin(), two.end(), memo[i]) != two.end())
            cout << 2 << " ";
        else
            cout << 3 << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}