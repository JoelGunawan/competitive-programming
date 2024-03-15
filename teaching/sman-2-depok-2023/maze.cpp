#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int grid[n + 1][m + 1];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j)
            cin >> grid[i][j];
    }
    int x, y;
    cin >> x >> y;
    queue<pair<int, pair<int, int>>> q;
    q.push({1, make_pair(x, y)});
    bool vis[n + 1][m + 1];
    memset(vis, 0, sizeof(vis));
    while(q.size()) {
        int dist = q.front().first; int x = q.front().second.first, y = q.front().second.second; 
        q.pop();
        //cout << dist << " " << x << " " << y << endl;
        if(vis[x][y] || grid[x][y] == -1)
            continue;
        vis[x][y] = 1;
        // di ujung/tidak?
        if(x == 1 || y == 1 || x == n || y == m) {
            cout << dist << endl;
            return 0;
        }
        q.push({dist + 1, make_pair(x + 1, y)});
        q.push({dist + 1, make_pair(x - 1, y)});
        q.push({dist + 1, make_pair(x, y + 1)});
        q.push({dist + 1, make_pair(x, y - 1)});
    }
}