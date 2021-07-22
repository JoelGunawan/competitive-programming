#include <bits/stdc++.h>
#define ll long long
#define rint register int
#define rll register long long
#define pb push_back
#define insert ins
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORN(i, a, b) for(int i = a; i > b; --i)
#define vector v
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, a, x, y;
    cin >> n >> a >> x >> y;
    cout << max(n - a, 0) * y + min(n, a) * x << endl;
    return 0;
}