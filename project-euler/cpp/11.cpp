#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int n = 20;
    int a[n][n];
    ifstream fin("11.txt");
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            fin >> a[i][j];
    ll res = 0;
    // horizontal
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n - 3; ++j)
        {
            ll local = a[i][j];
            for(int k = 1; k < 4; ++k)
                local *= a[i][j + k];
            res = max(local, res);
        }
    // vertical
    for(int i = 0; i < n - 3; ++i)
        for(int j = 0; j < n; ++j)
        {
            ll local = a[i][j];
            for(int k = 1; k < 4; ++k)
                local *= a[i + k][j];
            res = max(local, res);
        }
    // diagonal 1
    for(int i = 0; i < n - 3; ++i)
        for(int j = 0; j < n - 3; ++j)
        {
            ll local = a[i][j];
            for(int k = 1; k < 4; ++k)
                local *= a[i + k][j + k];
            res = max(local, res);
        }
    // diagonal 2
    for(int i = 0; i < n - 3; ++i)
        for(int j = 3; j < n; ++j)
        {
            ll local = a[i][j];
            for(int k = 1; k < 4; ++k)
                local *= a[i + k][j - k];
            res = max(local, res);
        }
    cout << res << endl;
    return 0;
}