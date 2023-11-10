#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ll long long
#define fi first
#define se second
using namespace std;
int n, m, r, c, x, y;
bool a[2000][2000], vis[2000][2000];
bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y] && !vis[x][y];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> r >> c >> x >> y;
    --r, --c;
    // modified djikstra
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            char z;
            cin >> z;
            a[i][j] = z == '.';
        }
    // fi -> amount of right, se.fi -> x, se.se -> y
    priority_queue<pair<int, pair<int, int>>> dj;
    dj.push(mp(0, mp(r, c)));
    int res = 0;
    while(dj.size() > 0)
    {
        int right = -dj.top().fi; pair<int, int> cor = dj.top().se;
        dj.pop();
        if(vis[cor.fi][cor.se] || right > y || c + right - cor.se > x)
            continue;
        vis[cor.fi][cor.se] = 1;
        ++res;
        if(valid(cor.fi, cor.se + 1))
            dj.push(mp(-(right + 1), mp(cor.fi, cor.se + 1)));
        if(valid(cor.fi, cor.se - 1))
            dj.push(mp(-right, mp(cor.fi, cor.se - 1)));
        if(valid(cor.fi + 1, cor.se))
            dj.push(mp(-right, mp(cor.fi + 1, cor.se)));
        if(valid(cor.fi - 1, cor.se))
            dj.push(mp(-right, mp(cor.fi - 1, cor.se)));
    }
    cout << res << endl;
    return 0;
}