#include <bits/stdc++.h>
#define pb push_back
#define ins isnert
#define fi first
#define se second
#define ll long long
#define endl "\n"
#define ld long double
#pragma GCC optimize("Ofast")
using namespace std;
ll n, A;
int main()
{
    cin >> n >> A;
    // set the upper bound to 60 because 2^N is always <= 60 (this theoretically could be much lower just for safety reasons it is at 60)
    // log2 of N should be enough
    ll ans = n;
    for(int i = 1; i <= 41; ++i)
    {
        // brute force
        // we sell i - 1 times
        // let's assume we sell
        // a[1], a[2], ... a[i - 1], pens
        // therefore, we know that the production rate after the last sell
        // is a[i - 1], therefore we know that the production rate is
        // a[1] * a[2] * ... * a[i - 1]
        // for the final production run, we will produce a[i] pens
        // therefore we can conclude that
        // a[1] * a[2] * ... * a[i] >= n
        // and that we need to find
        // the minimum value for A*(i - 1) + sum_of(a)
        // for each i value, we can find the minimum of sum_of(a)
        // because we know that a[1] * a[2] * ... * a[i] >= n
        // the optimal a[x] = n^(1 / i)
        ll tmp = pow(n, (1.0 / i));
        ll root = pow(tmp, i);
        for(int j = 0; j < 41; ++j)
        {
            if(root >= n)
            {
                ans = min(ans, tmp * i + j + A * (i - 1));
                break;
            }
            root /= tmp, root *= (tmp + 1);
        }
    }
    cout << ans << endl;
    return 0;
}