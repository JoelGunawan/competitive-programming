#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define pb push_back
using namespace std;
ll mod = 1e9 + 7;
ll powmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    else
    {
        ll tmp = powmod(a, b / 2); tmp *= tmp; tmp %= mod;
        return b & 1 ?(tmp * a) % mod : tmp;
    }
}
ll mulmod(ll a, ll b)
{
    return (a * b) % mod;
}
int main()
{
    ll n, s;
    cin >> n >> s;
    int nmod = n % mod, smod = s % mod;
    cout << (mulmod(mulmod(nmod, smod), mulmod(mulmod(nmod, smod) + 1, powmod(2, mod - 2))) - mulmod(nmod, mulmod(nmod - 1, powmod(2, mod - 2))) + mod) % mod << endl;
    return 0;
}