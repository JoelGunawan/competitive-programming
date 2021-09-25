#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define pb push_back
using namespace std;
int mod = 1e9 + 7;
int fact[(int)1e6 + 1], inversefact[(int)1e6 + 1];
ll powmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    else
    {
        ll tmp = powmod(a, b / 2); tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int mulmod(ll a, ll b)
{
    return (a * b) % mod;
}
ll combinmod(ll a, ll b)
{
    return mulmod(fact[a], mulmod(inversefact[b], inversefact[a - b]));
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    if(n - k + 1 >= k)
        cout << combinmod(n - k + 1, k);
    else
        cout << 0;
    cout << endl;
}
int main()
{
    fact[0] = 1, inversefact[0] = 1;
    for(int i = 1; i < 1e6 + 1; ++i)
        fact[i] = mulmod(fact[i - 1], i), inversefact[i] = powmod(fact[i], mod - 2);
    solve();
    return 0;
}