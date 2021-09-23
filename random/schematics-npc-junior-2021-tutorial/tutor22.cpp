#include <bits/stdc++.h>
using namespace std;
char a[10][10];
bool used[10][10];
void dfs(int i, int j)
{
    if(!(i >= 10 || i < 0 || j >= 10 || j < 0 || a[i][j] == '#' || used[i][j]))
    {
        used[i][j] = 1;
        dfs(i + 1, j), dfs(i - 1, j), dfs(i, j + 1), dfs(i, j - 1);
    }
}
int main()
{
    memset(used, 0, sizeof(used));
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
            cin >> a[i][j];
    int res = 0;
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
            if(!used[i][j] && a[i][j] != '#')
                ++res, dfs(i, j);
    cout << res << endl;
    return 0;   
}