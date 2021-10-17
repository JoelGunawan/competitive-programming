#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define lll __int128
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
int mod = 1e9 + 7;
ll powmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    else
    {
        ll tmp = powmod(a, b / 2); tmp *= tmp; tmp %= mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
void solve()
{
    ll m, n;
    cin >> m >> n;
    ll res_1 = ((powmod(2, m - 1) * 24) - 24) % mod, res_2 = ((powmod(2, n - 1) * 24)) % mod;
    cout << (res_1 + res_2) % mod;
}
int main()
{
    fast_io();
    solve();
    return 0;
}