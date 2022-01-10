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
void tc() {
    int n;
    cin >> n;
    int c[2 * n][2 * n];
    for(int i = 0; i < 2 * n; ++i) 
        for(int j = 0; j < 2 * n; ++j)
            cin >> c[i][j];
    ll x = 0;
    for(int i = n; i < 2 * n; ++i)
        for(int j = n; j < 2 * n; ++j)
            x += c[i][j];
    int res = 2e9;
    res = min(res, c[0][n]), res = min(res, c[0][2 * n - 1]);
    res = min(res, c[n - 1][n]), res = min(res, c[n - 1][2 * n - 1]);
    res = min(res, c[n][0]), res = min(res, c[n][n - 1]);
    res = min(res, c[2 * n - 1][0]), res = min(res, c[2 * n - 1][n - 1]);
    cout << res + x <<endl;
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