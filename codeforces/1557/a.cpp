#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.begin(), a.end());
        ll sum = 0;
        for(int i = 0; i < n - 1; ++i)
            sum += a[i];
        cout << (double)sum / (n - 1) + (double)a[n - 1] << endl;
    }
    return 0;
}