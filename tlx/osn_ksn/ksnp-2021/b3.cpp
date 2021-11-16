#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int h[n + 1], k[n + 1], d[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> h[i] >> k[i] >> d[i];
    // pake knapsack berkondisi
    int knapsack[n + 1][m + 1];
    memset(knapsack, 0, sizeof(knapsack));
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= m; ++j)
        {
            knapsack[i][j] = knapsack[i - 1][j];
            if(j >= h[i] && !d[i])
                knapsack[i][j] = max(knapsack[i][j], knapsack[i][j - h[i]] + k[i]);
            else if(j >= h[i])
                knapsack[i][j] = max(knapsack[i][j], knapsack[i - 1][j - h[i]] + k[i]);
        }
    }
    int res = 0;
    for(int i = 0; i <= m; ++i)
        res = max(knapsack[n][i], res);
    cout << res << endl;
    return 0;
}