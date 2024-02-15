#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    int h[n + 1], s[n + 1];
    for(int i = 1; i <= n; ++i) 
        cin >> h[i];
    for(int i = 1; i <= n; ++i)
        cin >> s[i];
    int dp[2][x + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= x; ++j) {
            if(j >= h[i])
                dp[(i & 1)][j] = max(dp[((i + 1) & 1)][j], dp[((i + 1) & 1)][j - h[i]] + s[i]);
            else
                dp[(i & 1)][j] = dp[((i + 1) & 1)][j];
        }
    }
    cout << dp[n & 1][x] << endl;
}