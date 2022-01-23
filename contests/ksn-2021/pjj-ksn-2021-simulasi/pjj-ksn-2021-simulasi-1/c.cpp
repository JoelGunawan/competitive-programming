#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int main()
{
    int a, b, c, n;
    cin >> a >> b >> c; n = a + b + c;
    ll x[n], y[n], z[n];
    for(int i = 0; i < n; ++i)
        cin >> x[i] >> y[i] >> z[i];
    if(c == 0)
    {
        // then do a binary
        // expected value, index
        pair<int, int> arr[n];
        for(int i = 0; i < n; ++i)
            arr[i] = {x[i] - y[i], i};
        sort(arr, arr + n);
        ll res = 0;
        for(int i = 0; i < b; ++i)
            res += y[arr[i].se];
        for(int i = b; i < n; ++i)
            res += x[arr[i].se];
        cout << res << endl;
        return 0;
    }
    else
    {
        ll dp[2][a + 1][b + 1][c + 1]; memset(dp, 0, sizeof(dp));
        dp[0][0][0][0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            // check dp sebelume yang ada state trs dijadiin ke dp yg sekarang
            for(int j = 0; j <= a && j < i; ++j)
                for(int k = 0; k <= b && j + k < i; ++k)
                    for(int l = 0; l <= c && j + k + l < i; ++l)
                    {
                        if(dp[(i + 1) % 2][j][k][l] != -1)
                        {
                            if(j != a)
                                dp[i % 2][j + 1][k][l] = max(dp[i % 2][j + 1][k][l], dp[(i + 1) % 2][j][k][l] + x[i - 1]);
                            if(k != b)
                                dp[i % 2][j][k + 1][l] = max(dp[i % 2][j][k + 1][l], dp[(i + 1) % 2][j][k][l] + y[i - 1]);
                            if(l != c)
                                dp[i % 2][j][k][l + 1] = max(dp[i % 2][j][k][l + 1], dp[(i + 1) % 2][j][k][l] + z[i - 1]);
                        }
                    }
        }
        cout << dp[n % 2][a][b][c] << endl;
        return 0;
    }
    ll x_y[n], x_z[n], y_x[n], y_z[n], z_x[n], z_y[n];
    for(int i = 0; i < n; ++i)
    {
        x_y[i] = x[i] - y[i];
        x_z[i] = x[i] - z[i];
        y_x[i] = -x_y[i];
        y_z[i] = y[i] - z[i];
        z_x[i] = -x_z[i];
        z_y[i] = -y_z[i];
    }
    // expected value and type and coordinate?
    pair<int, pair<int, int>> arr[3 * n]; 
    for(int i = 0; i < n; ++i)
        arr[3 * i] = {x_y[i] + x_z[i], {1, i}}, arr[3 * i + 1] = {y_x[i] + y_z[i], {2, i}}, arr[3 * i + 2] = {z_x[i] + z_y[i], {3, i}};
    sort(arr, arr + n);
    reverse(arr, arr + n);
    bool vis[n]; memset(vis, 0, sizeof(vis));
    /*
    for(int i = 0; i < n; ++i)
        cout << x_y[i] << " ";
    cout << endl;
    for(int i = 0; i < n; ++i)
        cout << x_z[i] << " ";
    cout << endl;
    for(int i = 0; i < n; ++i)
        cout << y_x[i] << " ";
    cout << endl;
    for(int i = 0; i < n; ++i)
        cout << y_z[i] << " ";
    cout << endl;
    for(int i = 0; i < n; ++i)
        cout << z_x[i] << " ";
    cout << endl;
    for(int i = 0; i < n; ++i)
        cout << z_y[i] << " ";
    cout << endl;
    */
   return 0;
}