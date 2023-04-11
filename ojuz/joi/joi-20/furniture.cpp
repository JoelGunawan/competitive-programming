#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    // tiap diagonal simpan
    // update neighbor bisa visit atau ga
    // kalo misal only node to be able to visit, berarti ga boleh
    // kalo bukan only node yg bisa visit, then absolutely fine
    // cek diagonal ada yg bs atau ga
    int cnt[n + m + 5];
    memset(cnt, 0, sizeof(cnt));
    int grid[n + 1][m + 1];
    bool src[n + 1][m + 1], tgt[n + 2][m + 2];
    memset(src, 0, sizeof(src));
    memset(tgt, 0, sizeof(tgt));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> grid[i][j];
    src[1][1] = tgt[n][m] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(!grid[i][j])
                src[i][j] |= src[i - 1][j] | src[i][j - 1];
        }
    }
    for(int i = n; i >= 1; --i) {
        for(int j = m; j >= 1; --j) {
            if(!grid[i][j]) {
                tgt[i][j] |= tgt[i + 1][j] | tgt[i][j + 1];
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(src[i][j] && tgt[i][j])
                ++cnt[i + j];
        }
    }
    //for(int i = 2; i <= n + m; ++i) {
    //    cout << cnt[i] << " ";
    //}
    cout << endl;
    int q;
    cin >> q;
    int vis[n + 1][m + 1];
    memset(vis, -1, sizeof(vis));
    for(int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        if(cnt[x + y] == 1 && src[x][y] && tgt[x][y]) {
            cout << 0 << endl;
            continue;
        }
        else {
            // hapus node sekarang dr cnt, dan update neighboring nodes
            queue<pair<int, int>> q;
            q.push({x - 1, y});
            q.push({x, y - 1});
            grid[x][y] = 1;
            if(src[x][y] && tgt[x][y])
                --cnt[x + y];
            src[x][y] = 0, tgt[x][y] = 0;
            while(!q.empty()) {
                int a = q.front().first, b = q.front().second;
                q.pop();
                if(vis[a][b] == i || a < 1 || b < 1 || grid[a][b])
                    continue;
                vis[a][b] = i;
                // change tgt
                int oldtgt = tgt[a][b];
                int ntgt = tgt[a + 1][b] | tgt[a][b + 1];
                if(oldtgt == ntgt)
                    continue;
                // beda berarti update previous jg
                if(oldtgt && src[a][b])
                    --cnt[a + b];
                tgt[a][b] = ntgt;
                q.push({a - 1, b});
                q.push({a, b - 1});
            }
            q.push({x + 1, y});
            q.push({x, y + 1});
            while(!q.empty()) {
                int a = q.front().first, b = q.front().second;
                q.pop();
                if(a > n || b > m || grid[a][b] || vis[a][b] == i)
                    continue;
                vis[a][b] = i;
                // change tgt
                int old = src[a][b];
                int ne = src[a - 1][b] | src[a][b - 1];
                if(old == ne)
                    continue;
                // beda berarti update previous jg
                if(old && tgt[a][b])
                    --cnt[a + b];
                src[a][b] = ne;
                q.push({a + 1, b});
                q.push({a, b + 1});
            }
            cout << 1 << endl;
        }
    }
}