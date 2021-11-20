#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#pragma GCC optimize("Ofast")
using namespace std;
ll mod = 998244353;
ll powmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    else if(b == 1)
        return a % mod;
    else
    {
        a %= mod;
        ll tmp = powmod(a, b / 2); tmp %= mod; tmp = (tmp * tmp) % mod;
        if(b % 2 == 0)
            return tmp;
        else
            return (tmp * a) % mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k, m;
    cin >> n >> k >> m;
    --mod;
    ll tmp = powmod(k, n) + mod;
    ++mod;
    cout << powmod(m, tmp) << endl;
    return 0;
}