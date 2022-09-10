#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    int dp[2][n + 1][k + 1], diag[2][n + k + 1][k + 1], pref[2][k + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    memset(diag, 0, sizeof(diag));
    memset(pref, 0, sizeof(pref));
    dp[0][0][0] = 1;
    dp[1][0][0] = 1;
    pref[0][0][0] = 1;
    pref[1][0][0] = 1;
    diag[0][k + 1][0] = 1;
    diag[1][k + 1][0] = 1;
    int zero[n + 1], one[n + 1];
    zero[0] = -100000, one[0] = -100000;
    for(int i = 1; i <= n; ++i) {
        zero[i] = zero[i - 1], one[i] = one[i - 1];
        if(s[i - 1] == 'A')
            one[i] = i;
        else if(s[i - 1] == 'B')
            zero[i] = i;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= k; ++j) {
            int cur_diag = i - j + k + 1, lastzero = zero[i], lastone = one[i];
            dp[0][i][j] = pref[1][j][i - 1];
            dp[1][i][j] = pref[0][j][i - 1];
            if(i - m >= 0 || lastzero > 0 || lastone > 0) {
                if(lastzero > i - m && lastzero > 0) {
                    dp[0][i][j] -= pref[1][j][lastzero - 1];
                }
                else if(i - m >= 0) {
                    dp[0][i][j] -= pref[1][j][i - m];
                }
                if(lastone > i - m && lastone > 0) {
                    dp[1][i][j] -= pref[0][j][lastone - 1];
                }
                else if(i - m >= 0) {
                    dp[1][i][j] -= pref[0][j][i - m];
                }
                dp[0][i][j] %= mod;
                dp[1][i][j] %= mod;
            }
            if(j != 0 && cur_diag - m + 1 >= 0) {
                dp[0][i][j] += diag[1][cur_diag - m + 1][j - 1];
                dp[0][i][j] %= mod;
                if(lastzero - (i - m - j + 1) > 0)
                    dp[0][i][j] -= diag[1][cur_diag - m + 1][min(lastzero - (i - m - j + 1) - 1, j - 1)], dp[0][i][j] %= mod;
                dp[1][i][j] += diag[0][cur_diag - m + 1][j - 1];
                dp[1][i][j] %= mod;
                if(lastone - (i - m - j + 1) > 0)
                    dp[1][i][j] -= diag[0][cur_diag - m + 1][min(lastone - (i - m - j + 1) - 1, j - 1)], dp[1][i][j] %= mod;
            }
            pref[0][j][i] = dp[0][i][j];
            pref[1][j][i] = dp[1][i][j];
            if(i != 0) {
                pref[0][j][i] += pref[0][j][i - 1];
                pref[1][j][i] += pref[1][j][i - 1];
                pref[0][j][i] %= mod;
                pref[1][j][i] %= mod;
            }
            diag[0][cur_diag][j] = dp[0][i][j];
            diag[1][cur_diag][j] = dp[1][i][j];
            if(j != 0) {
                diag[0][cur_diag][j] += diag[0][cur_diag][j - 1];
                diag[1][cur_diag][j] += diag[1][cur_diag][j - 1];
                diag[0][cur_diag][j] %= mod;
                diag[1][cur_diag][j] %= mod;
            }
        }
    }
    int res = dp[0][n][k] + dp[1][n][k];
    res %= mod;
    res += mod;
    res %= mod;
    cout << res << endl;
}