// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
vector<vector<int>> nxt = {{1, 0, -1, 0}, {0, 1, 0, -1}};
void tc() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    int lx = -1, ly = -1;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            if(arr[i][j] == 'L')
                lx = i, ly = j;
        }
    // first case -> from the lab, there must be exactly ONE adjacent cell that is a empty cell
    // just do a simple dfs
    function<bool(int, int)> empty_cell = [&] (int x, int y) -> bool {
        return !(x >= n || x < 0 || y >= m || y < 0 || arr[x][y] != '.');
    };
    function<void(int, int)> dfs = [&] (int x, int y) -> void {
        int cnt = 0;
        for(int i = 0; i < nxt[0].size(); ++i)
            cnt += empty_cell(x + nxt[0][i], y + nxt[1][i]);
        if(cnt <= 1) {
            arr[x][y] = '+';
            for(int i = 0; i < nxt[0].size(); ++i) {
                if(empty_cell(x + nxt[0][i], y + nxt[1][i]))
                    dfs(x + nxt[0][i], y + nxt[1][i]);
            }
        }
    };
    for(int i = 0; i < nxt[0].size(); ++i) {
        if(empty_cell(lx + nxt[0][i], ly + nxt[1][i]))
            dfs(lx + nxt[0][i], ly + nxt[1][i]);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j)
            cout << arr[i][j];
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) 
        tc();
    return 0;
}