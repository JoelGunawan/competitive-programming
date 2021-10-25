#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    fast_io();
    int n, x;
    cin >> n >> x;
    pair<double, int> a[n];
    // weight
    for(int i = 0; i < n; ++i)
        cin >> a[i].second;
    // price
    for(int i = 0; i < n; ++i)
        cin >> a[i].first, a[i].first /= a[i].second;
    double res = 0;
    sort(a, a + n);
    reverse(a, a + n);
    int i = 0;
    while(x > 0 && i != n)
    {
        res += min(a[i].second, x) * a[i].first;
        x -= min(a[i].second, x);
        ++i;
    }
    cout << fixed << setprecision(5);
    cout << res << endl;
    return 0;
}