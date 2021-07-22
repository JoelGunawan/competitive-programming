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
    v<v<ll>> arr;
    ll h, w, c;
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> h >> w >> c;
    arr = v<v<ll>>(h, v<ll>(w));
    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j)
            cin >> arr[i][j];
    v<v<ll>> dparr(h, v<ll>(w, 1e14)), dparr2(h, v<ll>(w, 1e14));
    FOR(i, 0, h)
    {
        FOR(j, 0, w)
        {
            if(i == 0 && j == 0)
                continue;
            else if(i == 0)
                dparr[i][j] = min(dparr[i][j - 1], arr[i][j - 1]);
            else if(j == 0)
                dparr[i][j] = min(dparr[i - 1][j], arr[i - 1][j]);
            else
                dparr[i][j] = min(dparr[i][j - 1], min(dparr[i - 1][j], min(arr[i - 1][j], arr[i][j - 1])));
            dparr[i][j] += c;
        }
    }
    FOR(i, 0, h)
    {
        FORN(j, w - 1, -1)
        {
            if(i == 0 && j == w - 1)
                continue;
            else if(j == w - 1)
                dparr2[i][j] = min(dparr2[i - 1][j], arr[i - 1][j]);
            else if(i == 0)
                dparr2[i][j] = min(dparr2[i][j + 1], arr[i][j + 1]);
            else
                dparr2[i][j] = min(dparr2[i - 1][j], min(arr[i - 1][j], min(dparr2[i][j + 1], arr[i][j + 1])));
            dparr2[i][j] += c;
        }
    }
    ll res = LLONG_MAX;
    FOR(i, 0, h)
    {
        FOR(j, 0, w)
        {
            if(i != 0 || j != 0)
                res = min(res, dparr[i][j] + arr[i][j]);
            if(i != 0 || j != w - 1)
                res = min(res, dparr2[i][j] + arr[i][j]);
        }
    }
    cout << res << endl;
    return 0;
}