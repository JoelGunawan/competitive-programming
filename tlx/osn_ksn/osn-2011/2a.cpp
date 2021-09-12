#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    char res[n][m];
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if((i & 1) && (j & 1))
                res[i - 1][j - 1] = '*';
            else if((i & 1) || (j & 1))
                res[i - 1][j - 1] = '$';
            else
                res[i - 1][j - 1] = '#';
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
            cout << res[i][j];
        cout << endl;
    }
    return 0;
}