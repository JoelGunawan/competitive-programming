#include <bits/stdc++.h>
using namespace std;
vector<int> edges[105];
bool vis[105];
vector<int> v;
void dfs(int nd) {
    vis[nd] = 1;
    v.push_back(nd);
    for(auto i : edges[nd]) {
        if(!vis[i])
            dfs(i);
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
    int bench = 0;
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            v.clear();
            dfs(i);
            bool semua_2 = 1;
            for(auto x : v) {
                if(edges[x].size() != 2)
                    semua_2 = 0;
            }
            if(semua_2 && v.size() % 2 == 1) {
                ++bench;
            }
        }   
    }
    int total = n - bench;
    if(total % 2 == 1)
        ++bench;
    cout << bench << endl;
}