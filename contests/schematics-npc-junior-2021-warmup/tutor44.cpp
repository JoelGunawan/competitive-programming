#include <bits/stdc++.h>
using namespace std;
int main()
{
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    int n, a, b;
    cin >> n >> a >> b;
    --a, --b;
    bool used[n][n];
    char maze[n][n];
    memset(used, 0, sizeof(used));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> maze[i][j];
    queue<pair<int, pair<int, int>>> q;
    if(maze[b][a] == 'x')
    {
        cout << -1 << endl;
        return 0;
    }
    q.push({0, {b, a}}); used[b][a] = 1;
    while(q.size() > 0)
    {
        pair<int, pair<int, int>> cur = q.front();
        q.pop();
        int dist = cur.first, x = cur.second.first, y = cur.second.second;
        if(x == 0 || y == 0 || x == n - 1 || y == n - 1)
        {
            cout << dist << endl;
            return 0;
        }
        else
        {
            for(int i = 0; i < 4; ++i)
            {
                if(x + dx[i] < n && x + dx[i] >= 0 && y + dy[i] < n && y + dy[i] >= 0 && !used[x + dx[i]][y + dy[i]] && maze[x + dx[i]][y + dy[i]] != 'x')
                    used[x + dx[i]][y + dy[i]] = 1, q.push({dist + 1, {x + dx[i], y + dy[i]}});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}