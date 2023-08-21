#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1];
    memset(a, -1, sizeof(a));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    bool vis[n + 1][m + 1];
    memset(vis, 0, sizeof(vis));
    // bfs -> queue<pair<int, pair<int, int>>> bfs;
    // fi -> dist
    // se.fi -> x
    // se.se -> y
    queue<pair<int, pair<int, int>>> bfs;
    int initx, inity;
    cin >> initx >> inity;
    int ans = -1;
    bfs.push(make_pair(1, make_pair(initx, inity)));
    while(bfs.size()) {
        int dist = bfs.front().first, x = bfs.front().second.first, y = bfs.front().second.second;
        bfs.pop();
        if(vis[x][y] || a[x][y] == -1)
            continue;
        // syarat di luar -> x = 1, x = n, y = 1, y = m
        vis[x][y] = 1;
        if(x == 1 || x == n || y == 1 || y == m) {
            // udh ketemu jawaban
            ans = dist;
            break;
        }
        // x + 1, y
        // ke bawah
        if(!vis[x + 1][y])
            bfs.push(make_pair(dist + 1, make_pair(x + 1, y)));
        // x, y + 1
        // ke kanan
        if(!vis[x][y + 1])
            bfs.push(make_pair(dist + 1, make_pair(x, y + 1)));
        // x - 1, y
        // ke atas
        if(!vis[x - 1][y])
            bfs.push_make_pair(dist + 1, make_pair(x - 1, y));
        // x, y - 1
        // ke kiri
        if(!vis[x][y - 1])
            bfs.push(make_pair(dist + 1, make_pair(x, y - 1)));
        // v -> bantu menandakan next
        // v itu simpan perbedaan x sm y
        // {x + 1, y + 0} -> x + 1, y
        // {x + 0, y + 1} -> x, y + 1
        // {x + (-1), y + 0} -> x - 1, y
        // {x + 0, y + (-1)} -> x, y - 1
        vector<pair<int, int>> v = {make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1)};
        for(auto i : v) {
            if(!vis[i.first + x][i.second + y]) {
                bfs.push(make_pair(dist + 1, make_pair(i.first + x, i.second + y)));
            }
        }
    }
    cout << ans << endl;
}