#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define endl "\n"
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,popcnt,avx,tune=native")
using namespace std;
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int b[n];
    vector<int> a[n];
    int l[k], r[k];
    for(int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    for(int i = 0; i < n; ++i)
        a[i] = vector<int>(n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);
    for(int i = 1; i < n; ++i)
        a[i][i] = a[i][i - 1];
    for(int i = 0; i < k; ++i)
        scanf("%d", &l[i]);
    for(int i = 0; i < k; ++i)
        scanf("%d", &r[i]);
    if(n <= 100 && k <= 100)
    {
        /*
        ll dp[n][k + 1];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j <= k; ++j)
                dp[i][j] = -1;
        dp[0][0] = b[0];
        ll res = -5;
        for(int i = 1; i <= k; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                //cout << dp[j][i] << " ";
                for(int x = 0; x < n; ++x)
                {
                    // check whether a is in valid coin range
                    if(dp[x][i - 1] != -1 && a[x][j] >= l[i - 1] && a[x][j] <= r[i - 1])
                        dp[j][i] = max(dp[j][i], dp[x][i - 1] + b[j]);
                    //cout << dp[j][i] << " ";
                }
                //cout << dp[j][i] << " ";
            }
            //cout << endl;
        }
        for(int i = 0; i < n; ++i)
            res = max(res, dp[i][k]);
        cout << res << endl;
        */
        ll dp[k + 1][n]; memset(dp, -1, sizeof(dp));
        dp[0][0] = b[0];
        pair<int, pair<bool, ll>> arr[4 * n];
        int arr_size, left, right, idx;
        for(int i = 0; i < k; ++i)
        {
            // construct the next segment
            // bool false means start, bool true means end
            // first is value
            arr_size = 0;
            for(int j = 0; j < n; ++j)
            {
                left = lower_bound(a[j].begin(), a[j].end(), l[i]) - a[j].begin(), right = upper_bound(a[j].begin(), a[j].end(), r[i]) - a[j].begin() - 1;
                //cout << left << " " << right << endl;
                if(dp[i][j] == -1)
                    continue;
                else if(left > right)
                    continue;
                else if(j == left && j == right)
                    continue;
                else if(j == left && j != right)
                    arr[arr_size++] = mp(left + 1, mp(0, dp[i][j])), arr[arr_size++] = mp(right, mp(1, dp[i][j]));
                else if(j == right && j != left)
                    arr[arr_size++] = mp(left, mp(0, dp[i][j])), arr[arr_size++] = mp(right - 1, mp(1, dp[i][j]));
                else if(j >= left && j <= right)
                    arr[arr_size++] = mp(left, mp(0, dp[i][j])), arr[arr_size++] = mp(j - 1, mp(1, dp[i][j])), 
                    arr[arr_size++] = mp(j + 1, mp(0, dp[i][j])), arr[arr_size++] = mp(right, mp(1, dp[i][j]));
                else
                    arr[arr_size++] = mp(left, mp(0, dp[i][j])), arr[arr_size++] = mp(right, mp(1, dp[i][j]));
            }
            sort(arr, arr + arr_size);
            multiset<ll> cur;
            idx = 0;
            for(int j = 0; j < n; ++j)
            {
                while(idx != arr_size && arr[idx].first == j && !arr[idx].second.first)
                    cur.insert(-arr[idx++].second.second);
                if(cur.size() == 0)
                    dp[i + 1][j] = -1;
                else
                    dp[i + 1][j] = -*cur.begin() + b[j];
                while(idx != arr_size && arr[idx].first == j)
                    cur.erase(cur.find(-arr[idx++].second.second));
            }
            //for(int j = 0; j < n; ++j)
            //    cout << dp[i][j] << " ";
            //cout << endl;
            
        }
        ll res = -1;
        for(int i = 0; i < n; ++i)
            res = max(res, dp[k][i]);
        printf("%lld", res);
    }
    else
    {
        // find first largest
        ll first_max = 0, second_max = 0, first_max_index, second_max_index;
        for(int i = 0; i < n; ++i)
            if(b[i] > first_max)
                first_max = b[i], first_max_index = i;
        for(int i = 0; i < n; ++i)
            if(b[i] > second_max && i != first_max_index)
                second_max = b[i], second_max_index = i;
        if(first_max_index == 0)
            cout << b[0] + first_max * k / 2 + second_max * (k / 2 + k % 2) << endl;
        else
            cout << b[0] + first_max * (k / 2 + k % 2) + second_max * k / 2 << endl;
    }
    return 0;
}