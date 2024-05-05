#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> edges(100005);
bool vis[100005];
void dfs(int nd) {
    vis[nd] = 1;
    //cout << nd << endl;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            dfs(i);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<int> v;
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            dfs(i);
            v.push_back(i);
        }
    }
    cout << v.size() - 1 << endl;
    for(int i = 1; i < v.size(); ++i) {
        cout << v[0] << " " << v[i] << endl;
    }
}