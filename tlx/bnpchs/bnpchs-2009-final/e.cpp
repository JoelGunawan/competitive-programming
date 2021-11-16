#include <bits/stdc++.h>
using namespace std;
char a[100][100];
bool used[100][100];
int r, c, b;
pair<int, int> bom[100][100];
bool valid(int x, int y) {
    return !(x < 0 || y < 0 || x >= r || y >= c);
}
bool dfs(int x, int y) {
    if(!valid(x, y) || used[x][y])
        return 0;
    used[x][y] = 1;
    if(a[x][y] == 'E')
        return 1;
    else if(a[x][y] != '#') {
        bool ans = 0;
        if(bom[x][y].first != -1) {
            if(a[bom[x][y].first][bom[x][y].second] == '#') {
                a[bom[x][y].first][bom[x][y].second] = '.';
                if(used[bom[x][y].first][bom[x][y].second])
                    used[bom[x][y].first][bom[x][y].second] = 0, ans = dfs(bom[x][y].first, bom[x][y].second);
            }
        }
        return dfs(x + 1, y) || dfs(x - 1, y) || dfs(x, y + 1) || dfs(x, y - 1) || ans;
    }
    else
        return 0;
}
void tc() {
    memset(used, 0, sizeof(used));
    for(int i = 0; i < 100; ++i)
        for(int j = 0; j < 100; ++j)
            bom[i][j] = {-1, -1};
    cin >> r >> c;
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            cin >> a[i][j];
    cin >> b;
    int rp, cp, rb, cb;
    for(int i = 0; i < b; ++i)
        cin >> rp >> cp >> rb >> cb, bom[rp - 1][cp - 1] = {rb - 1, cb - 1};
    bool ans;
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            if(a[i][j] == 'S')
                ans = dfs(i, j);
    if(ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--)
        tc();
}