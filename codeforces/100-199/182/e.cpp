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
int mod = 1e9 + 7;
void add(ll &a, ll b) {
    a = (a + b) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, l;
    cin >> n >> l;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi >> a[i].se;
    // dp[pos][width]
    // avoid duplicate: buat dp[pos][board_type][width] atau dp[pos][board_type][rotated]
    ll dp[l + 1][n][2];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= l; ++i) {
        //cout << endl;
        for(int j = 0; j < n; ++j) {
            if(i - a[j].fi == 0)
                dp[i][j][0] = 1;
            if(i - a[j].se == 0 && a[j].fi != a[j].se)
                dp[i][j][1] = 1;
            for(int k = 0; k < n; ++k) {
                if(j != k) {
                    if(i - a[j].fi < 0)
                        dp[i][j][0] = 0;
                    else if(a[j].fi == a[k].se)
                        add(dp[i][j][0], dp[i - a[j].fi][k][0]);
                    else if(a[j].fi == a[k].fi)
                        add(dp[i][j][0], dp[i - a[j].fi][k][1]);
                    
                    if(i - a[j].se < 0 || a[j].fi == a[j].se)
                        dp[i][j][1] = 0;
                    else if(a[j].se == a[k].se)
                        add(dp[i][j][1], dp[i - a[j].se][k][0]);
                    else if(a[j].se == a[k].fi)
                        add(dp[i][j][1], dp[i - a[j].se][k][1]);
                }
            }
            //cout << dp[i][j][0] << " " << dp[i][j][1] << endl;
        }
    }
    ll res = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < 2; ++j)
            res += dp[l][i][j];
    cout << res % mod << endl;
    return 0;
}