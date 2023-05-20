#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int lim = 1e5 + 5;
bool vis[lim];
long long res[lim][2];
int l[lim], r[lim];
vector<int> edges[lim];
void dfs(int nd) {
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            dfs(i);
            res[nd][0] += max(abs(r[i] - l[nd]) + res[i][1], abs(l[i] - l[nd]) + res[i][0]);
            res[nd][1] += max(abs(r[i] - r[nd]) + res[i][1], abs(l[i] - r[nd]) + res[i][0]);
        }
    }
}
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) 
        vis[i] = 0, edges[i].clear();
    for(int i = 1; i <= n; ++i)
        res[i][0] = res[i][1] = 0;
    for(int i = 1; i <= n; ++i)
        cin >> l[i] >> r[i];
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1);
    cout << max(res[1][0], res[1][1]) << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
    cin >> t;
    while(t--)
        solve();
}