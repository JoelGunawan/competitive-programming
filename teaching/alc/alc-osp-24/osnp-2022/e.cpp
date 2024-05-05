#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    long long dp[n + 1][m + 1];
    long long pref[n + 1][m + 1];
    long long nilai[n + 1][m + 1];
    memset(pref, 0, sizeof(pref));
    memset(dp, 0, sizeof(dp));
    memset(nilai, 0, sizeof(nilai));
    dp[1][1] = 1;
    // O(N^2*M^2)
    // jadi O(NM)
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + nilai[i][j];
            pref[i][j] %= mod;
            if(i != 1 || j != 1)
                dp[i][j] = pref[i][j]; // (kecuali base case)
            // tambah dari 
            // (i, j) ke (i + a[i][j], j + a[i][j])
            nilai[i][j] += dp[i][j];
            nilai[i][j] %+ mod;
            if(i + a[i][j] + 1 <= n) {
                nilai[i + a[i][j] + 1][j] -= dp[i][j];
                nilai[i + a[i][j] + 1][j] %= mod;
            }
            if(j + a[i][j] + 1 <= m) {
                nilai[i][j + a[i][j] + 1] -= dp[i][j];
                nilai[i][j + a[i][j] + 1] %= mod;
            }
            if(i + a[i][j] + 1 <= n && j + a[i][j] + 1 <= m) {
                nilai[i + a[i][j] + 1][j + a[i][j] + 1] += dp[i][j];
                nilai[i + a[i][j] + 1][j + a[i][j] + 1] %= mod;
            }
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + nilai[i][j];
            pref[i][j] %= mod;
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    if(dp[n][m] < 0)
        dp[n][m] += mod;
    cout << dp[n][m] << endl;
}