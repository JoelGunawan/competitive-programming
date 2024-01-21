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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    char a[n + 2][m + 2];
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    pair<int, int> pr[n + 1][m + 1];
    bool vis[n + 2][m + 2];
    memset(vis, 0, sizeof(vis));
    int x = 0, y = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] == 'A')
                x = i, y = j;
        }
    }
    queue<pair<pair<int, int>, pair<int, int>>> bfs;
    bfs.push(mp(mp(x, y), mp(-1, -1)));
    vector<pair<int, int>> nxt = {mp(0, 1), mp(1, 0), mp(-1, 0), mp(0, -1)};
    while(bfs.size()) {
        int x = bfs.front().fi.fi, y = bfs.front().fi.se, prx = bfs.front().se.fi, pry = bfs.front().se.se;
        //cout << x << " " << y << endl;
        //cout.flush();
        bfs.pop();
        //cout << "AFTER POP" << endl;
        //cout << a[x][y] << endl;
        //cout << vis[x][y] << endl;
        if(vis[x][y] || !(a[x][y] == '.' || a[x][y] == 'A' || a[x][y] == 'B'))
            continue;
        //cout << "TEST" << endl;
        vis[x][y] = 1;
        pr[x][y] = mp(prx, pry);
        for(auto i : nxt) {
            if(!vis[x + i.fi][y + i.se]) {
                //cout << "DEBUG2 " << x + i.fi << " " << y + i.se << endl;
                //cout.flush();
                bfs.push(mp(mp(x + i.fi, y + i.se), mp(x, y)));
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j)
            if(a[i][j] == 'B')
                x = i, y = j;
    }
    if(!vis[x][y]) {
        cout << "NO" << endl;
        return 0;
    }
    string res = "";
    while(x != -1) {
        pair<int, int> pre = pr[x][y];
        if(pre.fi == -1)
            break;
        if(pre.fi < x) {
            res += "D";
        }
        else if(pre.fi > x) {
            res += "U";
        }
        else if(pre.se > y) {
            res += "L";
        }
        else {
            res += "R";
        }
        x = pre.fi, y = pre.se;
    }
    reverse(res.begin(), res.end());
    cout << "YES" << endl;
    cout << res.size() << endl;
    cout << res << endl;
    return 0;
}