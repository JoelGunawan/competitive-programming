#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, in;
    cin >> n >> m;
    // either most left or most right
    int a[m + 1];
    memset(a, 0, sizeof(a));
    for(int i = 0; i < n; ++i)
        cin >> in, ++a[in];
    int res, maxval = 0, leftcounter = 0, rightcounter = 0;
    ll leftsum = 0, rightsum = 0;
    for(int i = 1; i <= m; ++i)
    {
        rightsum += a[i] * (i - 1);
        rightcounter += a[i];
    }
    for(int i = 1; i <= m; ++i)
    {
        if(leftsum + rightsum > maxval && !a[i])
        {
            maxval = leftsum + rightsum;
            res = i;
        }
        rightcounter -= a[i];
        rightsum -= rightcounter;
        leftcounter += a[i];
        leftsum += leftcounter;
    }
    if(maxval)
        cout << res << endl;
    else
        cout << -1 << endl;
    return 0;
}