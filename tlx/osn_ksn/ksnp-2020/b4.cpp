#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
using namespace std;
ll sqr(ll a) {
    return a * a;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    ll dp[n];
    dp[0] = 0;
    // mundur yg optimal pasti cuma maju 2 mundur 1
    // atau mundur 1 maju 2
    for(int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1] + sqr(a[i] - a[i - 1]);
        if(i != 1) {
            dp[i] = min(dp[i], dp[i - 2] + 3 * sqr(a[i] - a[i - 2]));
            dp[i] = min(dp[i], dp[i - 1] + sqr(a[i - 1] - a[i - 2]) + 3 * sqr(a[i - 2] - a[i]));
        }
        if(i != n - 1)
            dp[i] = min(dp[i], 3 * sqr(a[i + 1] - a[i - 1]) + dp[i - 1] + sqr(a[i + 1] - a[i]));
    }
    cout << dp[n - 1] << endl;
    return 0;
}