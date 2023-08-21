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
const int lim = 205;
vector<pair<int, int>> nxt = {mp(0, 1), mp(1, 0), mp(-1, 0), mp(0, -1)};
bool vis[lim][lim];
int n, m;
int dfs(int x, int y) {
    if(x < 1 || y < 1 || x > n || y > m || vis[x][y])   
        return 0;
    int ret = 1;
    vis[x][y] = 1;
    for(auto i : nxt) {
        if(!vis[x + i.fi][y + i.se])
            ret += dfs(x + i.fi, y + i.se);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // dfs tiap cc cek even parity
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            char x;
            cin >> x;
            vis[i][j] = x == '1';
        }
    }
    bool ans = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            int tmp = dfs(i, j);
            if(tmp & 1) {
                ans = 0;
            }
        }
    }
    if(ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}