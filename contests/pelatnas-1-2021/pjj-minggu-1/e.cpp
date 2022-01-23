#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#pragma GCC optimize("Ofast")
#define global_size 1001
using namespace std;
short max(short a, short b, short c, short d)
{
    return max(a, max(b, max(c, d)));
}
short min(short a, short b, short c)
{
    return min(a, min(b, c));
}
short a[10][10][global_size][global_size], memo[global_size];    
int f(int a)
{
    return a < 0 ? 0 : 1 << a;
}
struct sparse_table
{
    // memo basically converts the O(log n) time to find largest power of 2 to O(1)
    sparse_table()
    {
        memset(a, 0, sizeof(a));
        int cur = 2, tmp = 1;
        memo[0] = 0;
        for(int i = 1; i < global_size; ++i)
        {
            if(i >= cur)
                cur *= 2, ++tmp;
            memo[i] = tmp;
        }
    }  
    void build(vector<vector<short>> arr)
    {
        int n = arr.size(), m = arr[0].size();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                a[0][0][i][j] = arr[i][j];
        for(int i = 0; i < 10; ++i)
        {
            for(int j = 0; j < 10; ++j)
            {
                for(int k = 0; k + (f(i - 1)) < global_size; ++k)
                    for(int l = 0; l + f(j - 1) < global_size; ++l)
                    {
                        if(i != 0)
                            a[i][j][k][l] = max(a[i - 1][j][k][l], a[i - 1][j][k + (1 << (i - 1))][l]);
                        else if(j != 0)
                            a[i][j][k][l] = max(a[i][j - 1][k][l], a[i][j - 1][k][l + (1 << (j - 1))]);
                    }
            }
        }
    }
    short query(int x1, int y1, int x2, int y2)
    {
        int x_dist = x2 - x1 + 1, y_dist = y2 - y1 + 1, x_tmp = memo[x_dist], y_tmp = memo[y_dist];
        --x_tmp, --y_tmp;
        //cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x_dist << " " << y_dist << " " << x_tmp << " " << y_tmp << " " << x2 - (1 << x_tmp) + 1 << " " << y2 - (1 << y_tmp) + 1 << endl;
        return max(a[x_tmp][y_tmp][x1][y1], 
        a[x_tmp][y_tmp][x2 - (1 << x_tmp) + 1][y1], 
        a[x_tmp][y_tmp][x1][y2 - (1 << y_tmp) + 1],
        a[x_tmp][y_tmp][x2 - (1 << x_tmp) + 1][y2 - (1 << y_tmp) + 1]);
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sparse_table sp;
    int n, m;
    cin >> n >> m;
    vector<vector<short>> dp(n, vector<short>(m));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            int a;
            cin >> a;
            dp[i][j] = a;
            if(a == 1 && i != 0 && j != 0)
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1;
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    sp.build(dp);
    int t;
    cin >> t;
    while(t--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1, --x2, --y2;
        int left = 1, right = min(x2 - x1 + 1, y2 - y1 + 1), res = 0;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            int query = sp.query(x1 + mid - 1, y1 + mid - 1, x2, y2);
            if(query >= mid)
                res = mid, left = mid + 1;
            else
                right = mid - 1;
        }
        cout << res << endl;
    }
    return 0;
}