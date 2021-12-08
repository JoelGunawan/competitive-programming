#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ins insert
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define lll __int128
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int r, c;
    cin >> r >> c;
    int t[r][c];
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            cin >> t[i][j];
    int d;
    cin >> d;
    pair<int, int> a[d];
    int x, y;
    for(int i = 0; i < d; ++i) {
        cin >> x >> y;
    }
    --x, --y;
    priority_queue<pair<int, pair<int, int>>> dj;
    dj.push(mp(-t[0][0], mp(0, 0)));
    bool vis[r][c];
    memset(vis, 0, sizeof(vis));
    while(dj.size() > 0) {
        int dist = -dj.top().fi; pair<int, int> coords = dj.top().se;
        dj.pop();
        if(coords.fi == x && coords.se == y)
            cout << dist << endl, exit(0);
        vis[coords.fi][coords.se] = 1;
        if(coords.fi != 0 && (coords.se == 0 || coords.se == c - 1) && !vis[coords.fi - 1][coords.se])
            dj.push(mp(-(dist + t[coords.fi - 1][coords.se]), mp(coords.fi - 1, coords.se)));
        if(coords.fi != r - 1 && (coords.se == 0 || coords.se == c - 1) && !vis[coords.fi + 1][coords.se])
            dj.push(mp(-(dist + t[coords.fi + 1][coords.se]), mp(coords.fi + 1, coords.se)));
        if(coords.se != 0 && !vis[coords.fi][coords.se - 1])
            dj.push(mp(-(dist + t[coords.fi][coords.se - 1]), mp(coords.fi, coords.se - 1)));
        if(coords.se != c - 1 && !vis[coords.fi][coords.se + 1])
            dj.push(mp(-(dist + t[coords.fi][coords.se + 1]), mp(coords.fi, coords.se + 1)));
    }
    return 0;
}