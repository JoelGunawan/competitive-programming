#include <bits/stdc++.h>
typedef long long ll;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n;
    cin >> t >> n;
    string a, b;
    int points[n], required[n];
    memset(required, 0, sizeof(required));
    for(int i = 0; i < n; ++i)
    {
        cin >> a >> b >> points[i];
        // find the places where they have common chars
        required[i] = abs((int)a.size() - (int)b.size());
        for(int j = 0; j < min(a.size(), b.size()); ++j)
            if(a[j] != b[j])
                ++required[i];
    }
    // use knapsack/dp approach
    int arr[n + 1][t + 1];
    memset(arr, 0, sizeof(arr));
    int res = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < t + 1 - required[i]; ++j)
            arr[i + 1][j + required[i]] = max(arr[i + 1][j + required[i]], arr[i][j] + points[i]);
        for(int j = 0; j < t + 1; ++j)
            arr[i + 1][j] = max(arr[i + 1][j], arr[i][j]);
    }
    for(int i = 0; i < n + 1; ++i)
        for(int j = 0; j < t + 1; ++j)
            res = max(res, arr[i][j]);
        cout << res << endl;
    return 0;
}