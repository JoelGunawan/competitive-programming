#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> a[i][j];
    int tmp;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> tmp, a[i][j] ^= tmp;
    bool ans = 1;
    for(int i = 1; i < n; ++i)
    {
        int tmp = a[0][0] ^ a[i][0];
        for(int j = 1; j < m; ++j)
        // relative xor has to be the same for each column in the row, otherwise it is not possible
            if((a[i][j] ^ a[0][j]) != tmp)
            {
                cout << "NO" << endl;
                return 0;
            }
    }
    cout << "YES" << endl;
    return 0;
}