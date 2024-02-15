#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7;
int main() {
    int n, x;
    cin >> n >> x;
    ll dp[x + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int c[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    for(int i = 1; i <= x; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(c[j] <= i) {
                dp[i] += dp[i - c[j]];
            }
        }
        dp[i] %=  mod;
    }
    cout << dp[x] << endl;
}