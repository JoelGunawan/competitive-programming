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
void solve() {
    int n, m, b, w;
    cin >> n >> m >> b >> w;
    char ans[4 * n][4 * m];
    for(int i = 0; i < 4 * n; ++i)
        for(int j = 0; j < 4 * m; ++j)
            ans[i][j] = '.';
    // do bfs from 2, 2
    // need to makr indices that are not valid
    // not edge and not
    // mulai dari lurus n
    int wcnt = w, bcnt = b;
    for(int i = 1; i < 4 * n - 1; i += 2) {
        if(b)
            ans[i][1] = 'B', ans[i + 1][1] = 'W', --b, --w;
    }
    for(int i = 1; i < 4 * n - 1; i += 4) {
        for(int j = 3; j < 4 * m - 1; j += 2) {
            if(b)
                ans[i][j] = 'B', ans[i][j - 1] = 'W', --b, --w;
        }
    }
    for(int i = 0; i < 4 * n; ++i) {
        for(int j = 0; j < 4 * m; ++j) {
            if(ans[i][j] == 'B') {
                if(ans[i + 1][j] == '.' && w)
                    --w, ans[i + 1][j] = 'W';
                if(ans[i - 1][j] == '.' && w)
                    --w, ans[i - 1][j] = 'W';
                if(ans[i][j + 1] == '.' && w)
                    --w, ans[i][j + 1] = 'W';
                if(ans[i][j - 1] == '.' && w)
                    --w, ans[i][j - 1] = 'W';
            }
        }
    }
    if(bcnt == 0 && wcnt)
        ans[1][0] = 'W';
    int tmp1 = 0, tmp2 = 0;
    for(int i = 0; i < 4 * n; ++i) {
        for(int j = 0; j < 4 * m; ++j) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}