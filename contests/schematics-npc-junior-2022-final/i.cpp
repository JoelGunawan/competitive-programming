#include <bits/stdc++.h>
using namespace std;
const int lim = 1e3 + 5;
vector<pair<int, int>> edges[lim];
int main() {
    int n;
    cin >> n;
    string name[n + 1];
    int price[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> name[i] >> price[i];
    }
    int m;
    cin >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    int d;
    cin >> d;
    priority_queue<pair<int, int>> dj;
    dj.push({0, 0});
    pair<int, int> ans = {1e9, 0};
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    while(!dj.empty()) {
        int nd = dj.top().second, dist = -dj.top().first;
        dj.pop();
        if(vis[nd])
            continue; 
        vis[nd] = 1;
        if(dist <= d && nd != 0)
            ans = min(ans, {price[nd], nd});
        for(auto i : edges[nd]) {
            if(!vis[i.first]) {
                dj.push({-(dist + i.second), i.first});
            }
        }
    }
    cout << "hari ini makan di " << name[ans.second] << endl;
}