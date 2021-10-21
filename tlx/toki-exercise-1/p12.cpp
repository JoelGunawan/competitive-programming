#include <bits/stdc++.h>
using namespace std;
char a[80][80];
bool vis[80][80];
int n, m;
vector<vector<int>> next_node = {{1, 0, -1, 0}, {0, 1, 0, -1}};
bool is_valid(int x, int y)
{
    return a[x][y] == ' ' && !vis[x][y];
}
bool dfs(int x, int y)
{
    // if x or y is in the edge return 0
    //cout << x << " " << y << " " << a[x][y] << endl;
    if(vis[x][y])
        return 1;
    else if(x == 0 || x == n - 1 || y == 0 || y == m - 1)
        return 0;
    // else return neighboring nodes, if one of them is false, then we return false
    else
    {
        vis[x][y] = 1;
        bool res = 1;
        for(int i = 0; i < next_node[0].size(); ++i)
            if(is_valid(x + next_node[0][i], y + next_node[1][i]))
                res &= dfs(x + next_node[0][i], y + next_node[1][i]);
        return res;
    }
}
void test_case()
{
    memset(vis, 0, sizeof(vis));
    memset(a, 0, sizeof(a));
    cin >> n >> m;
    getchar();
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
            a[i][j] = getchar();
        getchar();
    }
    bool res = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(!vis[i][j] && a[i][j] == ' ')
                res |= dfs(i, j);
        }
    }
    if(res)
        cout << "YA";
    else
        cout << "TIDAK";
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}