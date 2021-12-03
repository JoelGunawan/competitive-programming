#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
void test_case()
{
    ll x0, n;
    cin >> x0 >> n;
    ll x = n / 4 * 4;
    for(ll i = x + 1; i <= n; ++i)
    {
        if(x0 & 1)
            x0 += i;
        else
            x0 -= i;
    }
    cout << x0 << endl;
}

int main()
{
    fast_io();
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}