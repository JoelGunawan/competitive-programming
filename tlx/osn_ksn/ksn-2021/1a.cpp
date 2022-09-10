#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
// subtask 2
/*
int main()
{
    int n, m, k, out = 0;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    for(int i = 0; i < 1 << n; ++i) {
        string tmp = "";
        bool valid = 1;
        for(int j = 0; j < n; ++j) {
            if(s[j] == '?') {
                if((1 << j) & i)
                    tmp += 'A';
                else
                    tmp += 'B';
            }
            else {
                if((1 << j) & i)
                    tmp += s[j];
                else
                    valid = 0;
            }
        }
        int streak, res = 0; char pr = 0;
        for(int j = 0; j < n; ++j) {
            if(tmp[j] != pr)
                pr = tmp[j], streak = 0;
            ++streak;
            if(streak >= m)
                ++res;
        }
        if(res == k && valid)
            ++out;
    }
    cout << out << endl;
    return 0;
}
*/
// subtask 4 (k = 0, m = 2)
/*
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int res1 = 1, res2 = 1;
    for(int i = 0; i < n; ++i) {
        if((i & 1 && s[i] == 'B') || (i % 2 == 0 && s[i] == 'A'))
            res1 = 0;
    }
    for(int i = 0; i < n; ++i) {
        if((i & 1 && s[i] == 'A') || (i % 2 == 0 && s[i] == 'B'))
            res2 = 0;
    }
    cout << res1 + res2 << endl;
}
*/

// subtask 5 (k = 0)
/*
int main()  {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    long long dp[n][2][m + 5];
    memset(dp, 0, sizeof(dp));
    if(s[0] == 'A')
        dp[0][0][1] = 1;
    else if(s[1] == 'B')
        dp[0][1][1] = 1;
    else
        dp[0][0][1] = 1, dp[0][1][1] = 1;
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j <= m; ++j) {
            dp[i][0][j] = dp[i - 1][0][j - 1];
            dp[i][1][j] = dp[i - 1][1][j - 1];
            if(s[i] == 'A')
                dp[i][1][j] = 0;
            if(s[i] == 'B')
                dp[i][0][j] = 0;
            dp[i][0][j] %= mod;
            dp[i][1][j] %= mod;
        }
        for(int k = 1; k < m; ++k) {
            if(s[i] != 'B')
                dp[i][0][1] += dp[i - 1][1][k];
            if(s[i] != 'A')
                dp[i][1][1] += dp[i - 1][0][k];
        }
    }
    long long res = 0;
    for(int i = 0; i < m; ++i) {
        res += dp[n - 1][0][i] + dp[n - 1][1][i];
        res %= mod;
    }
    cout << res << endl;
}
*/
// subtask 3, 6 (n <= 200)
/*
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    if(m == 1) {
        if(k != n)
            cout << 0 << endl;
        else {
            long long res = 1;
            for(int i = 0; i < n; ++i)
                if(s[i] == '?')
                    res *= 2, res %= mod;
            cout << res << endl;
        }
        return 0;
    }
    long long dp[n][2][m + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    if(s[0] == 'A') {
        if(m != 1)
            dp[0][0][1][0] = 1;
        else
            dp[0][0][1][1] = 1;
    }
    else if(s[0] == 'B') {
        if(m != 1)
            dp[0][1][1][0] = 1;
        else
            dp[0][1][1][1] = 1;
    }
    else {
        if(m != 1) {
            dp[0][0][1][0] = 1;
            dp[0][1][1][0] = 1;
        }
        else {
            dp[0][0][1][1] = 1;
            dp[0][1][1][1] = 1;
        }
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j <= m; ++j) {
            for(int l = 0; l <= k; ++l) {
                // transisi lanjutan
                if(j == m && l > 0) {
                    dp[i][0][j][l] = dp[i - 1][0][j][l - 1] + dp[i - 1][0][j - 1][l - 1];
                    dp[i][1][j][l] = dp[i - 1][1][j][l - 1] + dp[i - 1][1][j - 1][l - 1];
                }
                else if(j != m) {
                    dp[i][0][j][l] = dp[i - 1][0][j - 1][l];
                    dp[i][1][j][l] = dp[i - 1][1][j - 1][l];
                }
                if(s[i] == 'A')
                    dp[i][1][j][l] = 0;
                if(s[i] == 'B')
                    dp[i][0][j][l] = 0;
                dp[i][0][j][l] %= mod;
                dp[i][1][j][l] %= mod;
            }
        }
        for(int j = 1; j <= m; ++j)
            for(int l = 0; l <= k; ++l) {
                if(s[i] != 'B')
                    dp[i][0][1][l] += dp[i - 1][1][j][l];
                if(s[i] != 'A')
                    dp[i][1][1][l] += dp[i - 1][0][j][l];
                dp[i][0][1][l] %= mod;
                dp[i][1][1][l] %= mod;
            }
    }
    long long res = 0;
    for(int i = 1; i <= m; ++i)
        res += dp[n - 1][0][i][k] + dp[n - 1][1][i][k];
    cout << res % mod << endl;
}
*/
// subtask 7 (all chars are '?')
/*
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
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= k; ++j) {
            int cur_diag = i - j + k + 1;
            dp[0][i][j] = pref[1][j][i - 1];
            dp[1][i][j] = pref[0][j][i - 1];
            if(i - m >= 0) {
                dp[0][i][j] -= pref[1][j][i - m];
                dp[1][i][j] -= pref[0][j][i - m];
                dp[0][i][j] %= mod;
                dp[1][i][j] %= mod;
            }
            if(j != 0 && cur_diag - m + 1 >= 0) {
                dp[0][i][j] += diag[1][cur_diag - m + 1][j - 1];
                dp[1][i][j] += diag[0][cur_diag - m + 1][j - 1];
            }
            dp[0][i][j] %= mod;
            dp[1][i][j] %= mod;
            pref[0][j][i] = dp[0][i][j];
            pref[1][j][i] = dp[1][i][j];
            if(i != 0) {
                pref[0][j][i] += pref[0][j][i - 1];
                pref[1][j][i] += pref[1][j][i - 1];
            }
            pref[0][j][i] %= mod;
            pref[1][j][i] %= mod;
            diag[0][cur_diag][j] = dp[0][i][j];
            diag[1][cur_diag][j] = dp[1][i][j];
            if(j != 0) {
                diag[0][cur_diag][j] += diag[0][cur_diag][j - 1];
                diag[1][cur_diag][j] += diag[1][cur_diag][j - 1];
            }
            diag[0][cur_diag][j] %= mod;
            diag[1][cur_diag][j] %= mod;
        }
    }
    int res = dp[0][n][k] + dp[1][n][k];
    res %= mod;
    res += mod;
    res %= mod;
    cout << res << endl;
}
*/
// subtask 8 (full sol)
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
    zero[0] = -10000, one[0] = -10000;
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
                if(lastzero > i - m && lastzero > 0)
                    dp[0][i][j] -= pref[1][j][lastzero - 1];
                else if(i - m >= 0)
                    dp[0][i][j] -= pref[1][j][i - m];
                if(lastone > i - m && lastone > 0)
                    dp[1][i][j] -= pref[0][j][lastone - 1];
                else if(i - m >= 0)
                    dp[1][i][j] -= pref[0][j][i - m];
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