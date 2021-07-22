#include <bits/stdc++.h>
#define ll long long
#define rint register int
#define rll register long long
#define pb push_back
#define ins insert
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORN(i, a, b) for(int i = a; i > b; --i)
#define v vector
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    v<int> c(n);
    FOR(i, 0, n)
        cin >> c[i];
    map<int, int> counter;
    int cur = 0;
    FOR(i, 0, k)
    {
        if(!counter[c[i]])
            ++cur;
        ++counter[c[i]];
    }
    int res = cur;
    FOR(i, 0, n - k)
    {
        --counter[c[i]];
        if(!counter[c[i]])
            --cur;
        if(!counter[c[i + k]])
            ++cur;
        ++counter[c[i + k]];
        res = max(res, cur);
    }
    cout << res << endl;
    return 0;
}