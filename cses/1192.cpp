#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int lim = 1e3 + 5;
char a[lim][lim];
bool vis[lim][lim];
vector<int> edges[lim];
bool vis[lim];
// atas bawah kanan kiri
vector<pair<int, int>> nxt = {mp(0, 1), mp(1, 0), mp(-1, 0), mp(0, -1)};
void dfs(int x, int y) {
    vis[x][y] = 1;
    for(auto i : nxt) {
        if(a[x + i.fi][y + i.se] == '.' && !vis[x + i.fi][y + i.se])
            dfs(x + i.fi, y + i.se);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    }
    int rooms = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(!vis[i][j] && a[i][j] == '.')
                dfs(i, j), ++rooms;
        }
    }
    cout << rooms << endl;    
}