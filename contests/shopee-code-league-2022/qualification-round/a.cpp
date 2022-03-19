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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n][m];
    vector<pair<int, int>> coordinates[256];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if(a[i][j] != 0)
                coordinates[a[i][j]].pb(mp(i, j));
        }
    }
    int dp[n][m];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(i != 0 && j != 0) {
                dp[i][j] = INT_MAX;
                
            }
        }
    }
    return 0;
}