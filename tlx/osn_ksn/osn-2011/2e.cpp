#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int current = 1, x = 1, y = 1;
    while(current < k)
    {
        if(x == n || y == 1)
        {
            int total = x + y;
            y = min(total, m);
            x = total + 1 - y;
        }
        else
            ++x, --y;
        //cout << x << " " << y << endl;
        ++current;
    }
    cout << x << " " << y << endl;
    return 0;
}