#include <bits/stdc++.h>
using namespace std;
const int lim = 1e3 + 5;
int memo[lim];
// DP Top Down
int fib(int n) {
    // base case
    if(n == 1 || n == 2) {
        return 1;
    }
    if(memo[n] == -1) {
        memo[n] = fib(n - 1) + fib(n - 2);
        return memo[n];
    }
    else {
        return memo[n];
    }
    // bisa dijadikan:
    return memo[n] = memo[n] == -1 ? fib(n - 1) + fib(n - 2) : memo[n];
}
int main() {
    memset(memo, -1, sizeof(memo));
    cout << fib(10) << endl;
    // DP Top Down (kalo ternyata perlu nilainya, dihitung)
    // fib(10) -> fib(9) -> fib(8)
    // DP Bottom Up (hitung dari kecil ke besar)
    // fib(1) -> fib(2) -> fib(3)
    int dp[lim];
    dp[1] = 1, dp[2] = 1;
    for(int i = 3; i <= 10; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2]; // fibonacci
        cout << dp[i] << " ";
    }
    
}