#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    fast_io();
    int n, m, k;
    cin >> n >> m >> k;
    int x = 0, y = 0;
    int a[n][m];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> a[i][j];
    bool ans = 0;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            int cur = 1;
            if(i > 0)
                cur *= a[j][i - 1];
            if(j > 0)
                cur *= a[j - 1][i];
            if(i < m - 1)
                cur *= a[j][i + 1];
            if(j < n - 1)
                cur *= a[j + 1][i];
            if(cur == k)
            {
                x = j + 1, y = i + 1, ans = 1;
                break;
            }
        }
        if(ans)
            break;
    }  
    cout << x << " " << y << endl;
    return 0;
}