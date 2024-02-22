#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
// dp top down
const int lim = 1e6 + 5;
int memo[lim];
long long dp(int n) {
    if(n == 0)
        return 1;
    else if(n < 0)
        return 0;
    else if(memo[n] != 0)
        return memo[n];
    else
        return memo[n] = (dp(n - 1) + dp(n - 2) + dp(n - 3) + dp(n - 4) + dp(n - 5) + dp(n - 6)) % mod;
}
int main() {
    int n;
    cin >> n;
    // dp bottom up
    // dr base case ke case terakhir
    long long memo[n + 1];
    memset(memo, 0, sizeof(memo));
    for(int i = 1; i <= n; ++i) {
        for(int j = i - 1; j >= i - 6 && j > 0; --j) {
            memo[i] = (memo[i] + memo[j]) % mod;
        }
        // tambahin base case
        // base case: kalo n <= 6 ditambah 1 (karena ambil 1 dadu)
        if(i <= 6)
            ++memo[i];
        memo[i] %= mod;
    }
    // sifat dp: pasti ada urutan
    // dp[5] = dp[4] + dp[3]
    // dp[4] = dp[5] + dp[2]
    assert(dp(n) == memo[n]);
    cout << memo[n] << endl;
}