#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    int dp[k + 1];
    fill(dp, dp + k + 1, 1e9);
    dp[0] = 0;
    for(int i = 1; i <= k; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i >= a[j])
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }
    if(dp[k] >= 1e9)
        cout << -1 << endl;
    else
        cout << dp[k] << endl;
}