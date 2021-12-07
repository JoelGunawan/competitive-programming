#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define ins insert
using namespace std;
void test_case() {
    int n, m;
    cin >> n >> m;
    int p[n + 1], h[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> p[i];
    for(int i = 1; i <= n; ++i)
        cin >> h[i];
    vector<int> edges[n + 1];
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    bool valid = 1, vis[n + 1];
    memset(vis, 0, sizeof(vis));
    int subtree[n + 1]; memset(subtree, 0, sizeof(subtree));
    // returns the number of bad mood people
    function<int(int)> get_subtree = [&](int node) -> int {
        vis[node] = 1;
        subtree[node] = p[node];
        for(auto i : edges[node])
            if(!vis[i])
                subtree[node] += get_subtree(i);
        return subtree[node];
    };
    get_subtree(1);
    memset(vis, 0, sizeof(vis));
    function<int(int)> dfs = [&](int node) -> int {
        // yang penting itu banyak gc
        //if(2 * gc - subtree[node] <= h[node])
        int gc = 0;
        vis[node] = 1;
        for(auto i : edges[node])
            if(!vis[i])
                gc += dfs(i);
        if(abs(h[node]) > subtree[node] || 2 * gc - subtree[node] > h[node] || abs(subtree[node]) % 2 != abs(h[node]) % 2)
            valid = 0;
        gc = (subtree[node] + h[node]) / 2;
        return gc;
    };
    dfs(1);
    if(valid)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}   
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}