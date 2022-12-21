#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, root;
    cin >> n >> root;
    int m;
    cin >> m;
    vector<pair<int, int>> edges[n + 1];
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    
}