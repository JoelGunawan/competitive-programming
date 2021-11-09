#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, t;
    cin >> n >> t;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    ll prefix[n + 1];
    memset(prefix, 0, sizeof(prefix));
    for(int i = 1; i <= n; ++i)
        prefix[i] = prefix[i - 1] + a[i];
    ll res = 0;
    
    return 0;
}