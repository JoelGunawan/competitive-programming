#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        // we find the average of all the numbers
        ll lownum = 0;
        for(int i = 0; i < n; ++i)
            lownum += a[i];
        ll highcount = lownum % n, lowcount = n - highcount;
        cout << highcount * lowcount << endl;
    }
    return 0;
}