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
int dp[1005][1005];
int mod = 1e9 + 7;
int solve(int x, int y) {
    if(y > x || y < 0 || x < 0)
        return 0;
    if(x == 0 && y == 0)
        return 1;
    if(dp[x][y] != -1)
        return dp[x][y];
    int a = solve(x - 1, y - 1), b = solve(x, y + 1);
    if(y % 2 == 0) {
        // hasil dp tambah 1, karena ke parent
        //cout << x << " " << y << " " << a + b << endl;
        return dp[x][y] = (a + b + 1) % mod;
    }
    else {
        // hasil dp tidak tambah 1, karena tidak ke parent
        //cout << x << " " << y << " " << a + b - min({a, b, 1}) << endl;
        return dp[x][y] = (a + b - min({a, b, 1})) % mod;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << solve(n, 0) - 1 << endl;
    return 0;
}