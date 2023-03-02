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
char a[205][205];
int n, m;
string s, t;
bool as[205][205][205], at[205][205][205], svis[205][205][205], tvis[205][205][205];
vector<pair<int, int>> nxt = {mp(1, 0), mp(0, 1), mp(-1, 0), mp(0, -1)};
bool valid(int x, int y) {
    return x >= 1 && x <= n && y >= 0 && y <= m;
}
void sdfs(int x, int y, int idx) {
    svis[x][y][idx] = 1;
    if(a[x][y] == s[idx]) {
        as[x][y][idx] = 1;
        //cout << "S " << x << " " << y << " " << idx << endl;
        if(idx == s.size() - 1) {
            //cout << x << " " << y << endl;
            return;
        }
        // cek kiri, kanan, atas, bawah
        for(auto i : nxt) {
            if(valid(x + i.fi, y + i.se) && !svis[x + i.fi][y + i.se][idx + 1]) {
                sdfs(x + i.fi, y + i.se, idx + 1);
            }
        }
    }
}
void tdfs(int x, int y, int idx) {
    tvis[x][y][idx] = 1;
    if(a[x][y] == t[idx]) {
        at[x][y][idx] = 1;
        //cout << "T " << x << " " << y << " " << idx << endl;
        if(idx == t.size() - 1) {
            return;
        }
        // cek kiri, kanan, atas, bawah
        for(auto i : nxt) {
            if(valid(x + i.fi, y + i.se) && !tvis[x + i.fi][y + i.se][idx + 1]) {
                tdfs(x + i.fi, y + i.se, idx + 1);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string buang;
    cin >> buang;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    cin >> s >> t;
    // common end of prefix start of suffix
    // cari intersect mulai dari index ke berapa
    reverse(t.begin(), t.end());
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            sdfs(i, j, 0);
            tdfs(i, j, 0);
        }
    vector<int> common;
    reverse(t.begin(), t.end());
    for(int i = 0; i < min(s.size(), t.size()); ++i) {
        //cout << s.substr(s.size() - i - 1, i + 1) << " " << t.substr(0, i + 1) << endl;
        if(s.substr(s.size() - i - 1, i + 1) == t.substr(0, i + 1))
            common.pb(i + 1);
    }
    //for(auto i : common)
    //    cout << i << " ";
    //cout << endl;
    int ans = 2e9;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            for(auto k : common) {
                // abcde cdefg
                // common -> 3
                // as -> di index (i, j) ada prefix s sampai posisi ke s.size() - k
                // at -> di index (i, j) ada t
                // ab 
                // waktu cek c
                // cek posisi (i, j) dia bisa buat prefix S dari a hingga c
                // cek posisi (i, j) bisa buat t
                // abcefg
                // bzzzzz
                // cdefgz
                // abcde
                // cdefg
                // dua"nya memenuhi -> bisa (gabung)
                //if(i == 7 && j == 5) {
                //    cout << as[i][j][s.size() - k] << " " << at[i][j][t.size() - 1] << endl;
                //}
                if(as[i][j][s.size() - k] && at[i][j][t.size() - 1]) {
                    ans = min(ans, (int)s.size() + (int)t.size() - k);
                }
            }
        }
    }
    if(ans != 2e9) {
        cout << ans << endl, exit(0);
    }
    bool vis[n + 1][m + 1];
    memset(vis, 0, sizeof(vis));
    queue<pair<pair<int, int>, int>> bfs;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(as[i][j][s.size() - 1])
                bfs.push(mp(mp(i, j), 0));
        }
    }
    while(bfs.size()) {
        int x = bfs.front().fi.fi, y = bfs.front().fi.se, dist = bfs.front().se;
        bfs.pop();
        if(vis[x][y])
            continue;
        vis[x][y] = 1;
        if(at[x][y][t.size() - 1]) {
            ans = dist + s.size() + t.size() - 1;
            break;
        }
        for(auto i : nxt) {
            if(!vis[x + i.fi][y + i.se] && valid(x + i.fi, y + i.se)) {
                bfs.push(mp(mp(x + i.fi, y + i.se), dist + 1));
            }
        }
    }
    if(ans == 2e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}