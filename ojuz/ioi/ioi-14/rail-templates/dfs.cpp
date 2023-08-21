#include <bits/stdc++.h>
using namespace std;
bool vis[1005][1005];
int grid[1005][1005];
vector<int> edges[100005];
void dfs(int x, int y) {
    vis[x][y] = 1;
    // konsep dfs:
    // cek tiap edge
    // di tiap edge, cek udh visited belum
    // belum visited -> dfs ke situ
    /*
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    */
    if(!vis[x + 1][y])
        dfs(x + 1, y);
    if(!vis[x - 1][y])
        dfs(x - 1, y);
    if(!vis[x][y + 1])
        dfs(x, y + 1);
    if(!vis[x][y - 1])
        dfs(x, y - 1);
}
int main() {
    
}