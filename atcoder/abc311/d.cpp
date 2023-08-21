// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    char grid[n + 1][m + 1];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> grid[i][j];
    bool possible[n + 1][m + 1];
    bool vis[n + 1][m + 1];
    queue<pair<int, int>> q;
    memset(vis, 0, sizeof(vis));
    memset(possible, 0, sizeof(possible));
    q.push(mp(2, 2));
    vector<pair<int, int>> nx = {mp(1, 0), mp(0, 1), mp(-1, 0), mp(0, -1)};
    while(q.size()) {
        int x = q.front().fi, y = q.front().se;
        q.pop();
        if(vis[x][y])
            continue;
        possible[x][y] = 1;
        vis[x][y] = 1;
        for(auto p : nx) {
            int a = x, b = y;
            while(grid[a + p.fi][b + p.se] == '.') {
                a += p.fi;
                b += p.se;
                possible[a][b] = 1;
            }
            if(!vis[a][b])
                q.push(mp(a, b));
        }
    }
    int res = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(possible[i][j])
                ++res;
    cout << res << endl;
    return 0;
}