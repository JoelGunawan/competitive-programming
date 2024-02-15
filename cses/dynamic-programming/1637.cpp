#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int dp[n + 1];
    fill(dp, dp + n + 1, 1e9);
    dp[0] = 0;
    for(int i = 1; i <= n; ++i) {
        vector<int> digits;
        int tmp = i;
        while(tmp) {
            digits.push_back(tmp % 10);
            tmp /= 10;
        }
        for(auto x : digits)
            dp[i] = min(dp[i], dp[i - x] + 1);
    }
    cout << dp[n] << endl;
}