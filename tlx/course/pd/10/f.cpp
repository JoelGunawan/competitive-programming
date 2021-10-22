#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize("Ofast")
using namespace std;
int pow(int a, int b)
{
    int res = 1;
    for(int i = 0; i < b; ++i)
        res *= a;
    return res;
}
int main()
{
    int n, d;
    cin >> n >> d;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    int min_dist = INT_MAX, max_dist = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            // find tingkat kedekatan
            int cur = pow(abs(a[i].first - a[j].first), d) + pow(abs(a[i].second - a[j].second), d);
            min_dist = min(min_dist, cur), max_dist = max(max_dist, cur);
        }
    }
    cout << min_dist << " " << max_dist << endl;
    return 0;
}