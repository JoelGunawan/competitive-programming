#include <bits/stdc++.h>
typedef long long ll;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
int mod = 1e9 + 7;
using namespace std;
int main()
{
    ll n, m, x;
    cin >> n >> m;
    ll res = 0;
    for(ll i = 0; i < n; ++i)
        res += ((i + 1) * (i + 1) + i * (i + 1) / 2 * m), res %= mod;
    cout << res << endl;
    return 0;
}