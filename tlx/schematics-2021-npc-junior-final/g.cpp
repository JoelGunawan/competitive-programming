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
ll fact[(int)1e6 + 1];
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
ll combinmod(ll a, ll b)
{
    if(a < b)
        return 0;
    else if(a == b)
        return 1;
    else
        return (((fact[a] * powmod(fact[b], mod - 2)) % mod) * powmod(fact[a - b], mod - 2)) % mod;
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // basically a nim game with n stacks, the winning state is the xor of all the states
    // which means we find the counter of all the arrays
    // and a valid arrangement is an arrangement such that the xor of all the heaps is 0
    // use 2SAT?
    // if a graph
}
int main()
{
    fast_io();
    solve();
    return 0;
}