#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ins insert
#define pf push_front
#define pq priority_queue
#define ll long long
#define lll long long long
#define lb lower_bound
#define ub upper_bound
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
void test_case()
{
    int n, k;
    cin >> n >> k;
    if(!(k & 1))
    {
        // easy constructive algo
        int cur = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < k / 2; ++j)
                cout << cur + j + 1 << " ";
            for(int j = 0; j < k / 2; ++j)
                cout << n * k - (cur +j) << " ";
            cout << endl;
            cur += k / 2;
        }
    }
    else if((n & 1) && (k & 1))
    {
        // what matters is the last 3 lines, the rest don't matter
        int res[n][k]; ll sum[n];
        memset(sum, 0, sizeof(sum));
        memset(res, 0, sizeof(res));
        int cur = 1;
        for(int i = 0; i < k - 2; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i & 1)
                    res[j][i] = cur + (n - j - 1);
                else
                    res[j][i] = cur + j;
                sum[j] += res[j][i];
            }
            cur += n;
        }
        //for(int i = 0; i < n; ++i)
        //{
        //    for(int j = 0; j < k - 2; ++j)
        //        cout << res[i][j] << " ";
        //    cout << endl;
        //}
        // for last 2 lines
        int highest = n * k;
        for(int i = 0; i <= n / 2 + 1; ++i)
            res[i][k - 2] = highest - 2 * i;
        for(int i = 0; i < n / 2 + 1; ++i)
            res[i + n / 2 + 1][k - 2] = highest - 1 - 2 * i;
        highest -= n;
        for(int i = 0; i <= n / 2 + 1; ++i)
            res[i][k - 1] = highest - (n / 2 - i);
        for(int i = 0; i < n / 2; ++i)
            res[i + n / 2 + 1][k - 1] = highest - n + i + 1;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < k; ++j)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }
    else
    {
        int res[n][k];
        memset(res, 0, sizeof(res));
        int cur = 1;
        for(int i = 0; i < k - 2; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i & 1)
                    res[j][i] = cur + (n - j - 1);
                else
                    res[j][i] = cur + j;
            }
            cur += n;
        }
        // need code
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < k; ++j)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }
}
int main()
{
    fast_io();
    test_case();
    return 0;
}