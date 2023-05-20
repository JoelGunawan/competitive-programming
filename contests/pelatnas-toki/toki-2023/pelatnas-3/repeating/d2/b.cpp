#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
using namespace std;
pair<int, int> arr[1000005];
char a[1005][1005];
bool vis[1005][1005];
int head[1005][1005], pref[1005][1005], n, m;
int nxa[] = {1, 0, -1, 0}, nxb[] = {0, 1, 0, -1};
void dfs(int x, int y, char e, int c) {
    if(x <= 0 || y <= 0 || x > n || y > m || vis[x][y] || a[x][y] != e) {
        return;
    }
    vis[x][y] = 1;
    head[x][y] = c;
    for(int i = 0; i < 4; ++i) {
        dfs(x + nxa[i], y + nxb[i], e, c);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    }
    int glob = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            if(!vis[i][j]) {
                arr[glob] = {i, j};
                dfs(i, j, a[i][j], glob++);
                pref[i][j]++;
            }
        }
    }
    int q;
    cin >> q;
    for(int qe = 0; qe < q; ++qe) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        set<int> s;
        for(int i = x1; i <= x2; ++i) {
            if(arr[head[i][y1]].fi < x1 || arr[head[i][y1]].fi > x2 || arr[head[i][y1]].se < y1 || arr[head[i][y1]].se > y2) {
                s.insert(head[i][y1]);
            }
        }
        for(int i = x1; i <= x2; ++i) {
            if(arr[head[i][y2]].fi < x1 || arr[head[i][y2]].fi > x2 || arr[head[i][y2]].se < y1 || arr[head[i][y2]].se > y2) {
                s.insert(head[i][y2]);
            }
        }
        for(int i = y1; i <= y2; ++i) {
            if(arr[head[x2][i]].fi < x1 || arr[head[x2][i]].fi > x2 || arr[head[x2][i]].se < y1 || arr[head[x2][i]].se > y2) {
                s.insert(head[x2][i]);
            }
        }
        for(int i = y1; i <= y2; ++i) {
            if(arr[head[x1][i]].fi < x1 || arr[head[x1][i]].fi > x2 || arr[head[x1][i]].se < y1 || arr[head[x1][i]].se > y2) {
                s.insert(head[x1][i]);
            }
        }
        cout << s.size() + pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1] << endl;
    }
}