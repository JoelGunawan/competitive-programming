#include <bits/stdc++.h>
#define endl "\n"
#define rll register int_fast64_t
#define rint register int_fast32_t
#define pb push_back
#define insert ins
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORN(i, a, b) for(int i = a; i > b; --i)
#define v vector
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    rint num = 100, tmp = num * (num + 1) / 2;
    cout << tmp * tmp - num * (num + 1) * (2 * num + 1) / 6 << endl;
    return 0;
}