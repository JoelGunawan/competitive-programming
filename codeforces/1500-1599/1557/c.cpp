#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
ll mod = 1e9 + 7;
ll fact[(int)(2 * 1e5 + 1)];
ll mulmod(ll a, ll b)
{
    return (a * b) % mod;
}
ll powmod(ll a, ll b)
{
    if(b <= 0)
        return 1;
    else
    {
        ll tmp = powmod(a, b / 2);
        return b & 1 ? mulmod(tmp, mulmod(tmp, a)) : mulmod(tmp, tmp);
    }
}
ll addmod(ll a, ll b)
{
    return (a + b) % mod;
}
ll combinmod(ll x, ll y)
{
    return mulmod(fact[x], mulmod(powmod(fact[y], mod - 2), powmod(fact[x - y], mod - 2)));
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    fact[0] = 1;
    for(int i = 1; i < 2 * 1e5 + 1; ++i)
        fact[i] = mulmod(fact[i - 1], i);
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        ll x = 0;
        for(int i = 0; i < n; i += 2)
            x = addmod(x, combinmod(n, i));
        if(n & 1)
            cout << powmod((1 + x), k) << endl;
        else
        {
            ll res = 0;
            for(int i = 0; i <= k; ++i)
                res = addmod(res, mulmod(powmod(powmod(2, i - 1), n), powmod(x, k - i)));
            cout << res << endl;
        }
    }
    return 0;
}