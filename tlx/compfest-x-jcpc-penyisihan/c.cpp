#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int memo[5 * (int)1e6 + 1];
    memset(memo, 0, sizeof(memo));
    int root, res;
    bool perfectsquare;
    for(int i = 0; i < n; ++i)
    {
        // find all factors of the current number
        root = sqrt(a[i]), perfectsquare = (root == sqrt(a[i]));
        for(int j = 1; j <= root; ++j)
        {
            if(a[i] % j == 0)
            {
                ++memo[j];
                if(j != root || !perfectsquare)
                    ++memo[a[i] / j];
            }
        }
    }
    for(int i = 0; i < 5 * 1e6 + 1; ++i)
        if(memo[i] >= m)
            res = i;
    cout << res << endl;
    return 0;
}