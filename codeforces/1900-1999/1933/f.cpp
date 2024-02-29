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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // shortest path to last column
    // then from there just calculate which one is more optimal (can go up or down there)
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        bool a[n][m];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                cin >> a[i][j];
        // fi -> dist
        // se -> coords
        queue<pair<int, pair<int, int>>> bfs;
        bfs.push(mp(0, mp(0, 0)));
        vector<pair<int, int>> nxt = {mp(2, 0), mp(1, 1)};
        int dist[n][m];
        memset(dist, -1, sizeof(dist));
        while(bfs.size()) {
            int d = bfs.front().fi, x = bfs.front().se.fi, y = bfs.front().se.se;
            bfs.pop();
            if(x < 0 || x >= n || y < 0 || y >= m || dist[x][y] != -1 || a[x][y])
                continue;
            dist[x][y] = d;
            if(!a[(x + 1) % n][y])
                bfs.push(mp(d + 1, mp((x + 2) % n, y)));
            bfs.push(mp(d + 1, mp((x + 1) % n, y + 1)));
        }
        int res = 1e9;
        for(int i = 0; i < n; ++i) {
            if(dist[i][m - 1] == -1)
                continue;
            int actual_row = i - dist[i][m - 1];
            actual_row %= n;
            actual_row += n;
            actual_row %= n;
            res = min(res, dist[i][m - 1] + min(actual_row + 1, n - 1 - actual_row));
        }
        if(res == 1e9)
            cout << -1 << endl;
        else
            cout << res << endl;
    }
    return 0;
}