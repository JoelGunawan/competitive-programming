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
const int lim = 25;
char a[lim][lim];
bool vis[lim][lim];
vector<pair<int, int>> nxt = {mp(1, 0), mp(0, 1), mp(-1, 0), mp(0, -1)};
int r, c;
bool valid(int x, int y) {
    return x >= 1 && y >= 1 && x <= r && y <= c && !vis[x][y];
}
void dfs(int x, int y, set<pair<int, int>> &s) {
    vis[x][y] = 1;
    for(auto i : nxt) {
        if(valid(x + i.fi, y + i.se) && a[x + i.fi][y + i.se] == 'W')
            dfs(x + i.fi, y + i.se, s);
        else if(valid(x + i.fi, y + i.se) && a[x + i.fi][y + i.se] == '.')
            s.ins(mp(i.fi + x, i.se + y));
    }
}
void solve() {
    cin >> r >> c;
    for(int i = 1; i <= r; ++i) {
        for(int j = 1; j <= c; ++j) {
            cin >> a[i][j];
            vis[i][j] = 0;
        }
    }
    bool ans = 0;
    for(int i = 1; i <= r; ++i) {
        for(int j = 1; j <= c; ++j) {
            if(a[i][j] == 'W' && !vis[i][j]) {
                set<pair<int, int>> tmp;
                dfs(i, j, tmp);
                //cout << tmp.size() << endl;
                if(tmp.size() == 1)
                    ans = 1;
            }
        }
    }
    if(ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}