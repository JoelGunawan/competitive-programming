#include <bits/stdc++.h>

#define ll long long
#define dbl double
#define ldbl long double
#define ull unsigned long long
using namespace std;

int mod = 1e9 + 7;

ll factmod(ll n)
{
    ull res = 1;
    for(int i = 2; i <= n; ++i) res = (res * i) % mod;
    return res;
}

ll powertwomod(ll n)
{
    ll res = 1;
    while(n > 0)
    {
        res = res<<min(32, (int)n);
        res %= mod;
        n -= 32;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(15);
    ll n;
    cin >> n;
    ll res = (factmod(n) - powertwomod(n - 1)) % mod;
    if(res < 0) res += mod;
    cout << res << "\n";
    return 0;
}
