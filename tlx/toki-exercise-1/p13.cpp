#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[500][500];
bool vis[500][500];
vector<vector<int>> next_node = {{1, 0, -1, 0}, {0, 1, 0, -1}};
bool is_valid(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < m && a[x][y] != '#' && !vis[x][y];
}
int dfs(int x, int y)
{
    int res = 1;
    vis[x][y] = 1;
    for(int i = 0; i < next_node[0].size(); ++i)
        if(is_valid(x + next_node[0][i], y + next_node[1][i]))
            res += dfs(x + next_node[0][i], y + next_node[1][i]);
    return res;
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> a[i][j];
    int b, k;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            if(a[i][j] == 'K')
                k = dfs(i, j), memset(vis, 0, sizeof(vis));
            else if(a[i][j] == 'B')
                b = dfs(i, j), memset(vis, 0, sizeof(vis));
        }
    if(k > b)
        cout << "K " << k - b << endl;
    else if(k < b)
        cout << "B " << b - k << endl;
    else
        cout << "SERI" << endl;
    return 0;
}