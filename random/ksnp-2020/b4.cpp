#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll square(ll a)
{
    return a * a;
}
int main()
{
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    ll dp[n];
    dp[0] = 0, dp[1] = (a[1] - a[0]) * (a[1] - a[0]);
    for(int i = 2; i < n; ++i)
        dp[i] = min(dp[i - 1] + square(a[i] - a[i - 1]), dp[i - 2] + 3 * square(a[i] - a[i - 2]));
    cout << dp[n - 1] << endl;
    return 0;
}