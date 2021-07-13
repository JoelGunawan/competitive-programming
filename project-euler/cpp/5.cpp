#include <bits/stdc++.h>
#define endl "\n"
#define rll register int_fast64_t
#define rint register int_fast32_t
#define ll long long
#define pb push_back
#define insert ins
#define FOR(i, a, b) for(rint i = a; i < b; ++i)
#define FORN(i, a, b) for(rint i = a; i > b; --i)
#define v vector
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
ll gcd(rll a, rll b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    rll res = 1; rint lim = 20;
    FOR(i, 2, 20 + 1)
        res *= i / gcd(res, i);
    cout << res << endl;
    return 0;
}