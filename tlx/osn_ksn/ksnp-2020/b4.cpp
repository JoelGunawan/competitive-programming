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
    {
        
    }
    return 0;
}