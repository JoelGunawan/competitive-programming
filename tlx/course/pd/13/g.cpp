#include <bits/stdc++.h>
using namespace std;
int a[25][25], m, n;
bool vis[25][25];
vector<vector<int>> next_move = {{1, 0, -1, 0}, {0, 1, 0, -1}};
int dfs(int x, int y, int colour)
{
    if(x < 0 || x >= m || y < 0 || y >= n || a[x][y] != colour || vis[x][y])
        return 0;
    else
    {
        int res = 1;
        vis[x][y] = 1;
        for(int i = 0; i < next_move[0].size(); ++i)
            res += dfs(x + next_move[0][i], y + next_move[1][i], colour);
        return res;
    }
}
int main()
{
    cin >> m >> n;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    int b, k;
    cin >> b >> k;
    int z = dfs(b, k, a[b][k]);
    cout << z * (z - 1) << endl;
    return 0;
}