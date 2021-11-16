#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string subsoal;
    int n, k;
    cin >> subsoal >> n >> k;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // O(NK) or O(NK log NK)
    ll dp[n][k + 1]; memset(dp, 0, sizeof(dp));
    cout << dp[n - 1][k] << endl;
    return 0;
}