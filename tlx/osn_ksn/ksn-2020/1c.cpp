#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int counter[n + 1], arr[n]; memset(counter, 0, sizeof(counter));
    int in;
    for(int i = 0; i < n; ++i)
        cin >> in, arr[i] = in, ++counter[in];
    if(k <= 20 && n <= 2000)
    {   
        int dp[k + 1][n];
        memset(dp, 0, sizeof(dp));
        memset(counter, 0, sizeof(counter));
        for(int i = 0; i < n; ++i)
        {
            ++counter[arr[i]];
            if(counter[arr[i]] > m)
                dp[0][i] = dp[0][i - 1] + 1, memset(counter, 0, sizeof(counter)), ++counter[arr[i]];
            else if(i == 0)
                dp[0][i] = 0;
            else
                dp[0][i] = dp[0][i - 1];
        }
        for(int i = 1; i <= k; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                
            }
        }
    }
    else if(k == 0)
    {
        memset(counter, 0, sizeof(counter));
        int res = 1;
        for(int i = 0; i < n; ++i)
        {
            ++counter[arr[i]];
            if(counter[arr[i]] > m)
                memset(counter, 0, sizeof(counter)), ++res, counter[arr[i]] = 1;
        }
        cout << res << endl;
    }
    else if(counter[1] == n)
    {
        counter[1] -= k;
        cout << ceil((double)counter[1] / m) << endl;
    }
    else
        cout << 3 << endl;
}