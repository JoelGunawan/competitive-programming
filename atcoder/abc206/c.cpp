#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    ll res = (ll)n * (ll)(n - 1) / 2;
    sort(a.begin(), a.end());
    int streak = 0;
    for(int i = 0; i < n; ++i)
    {
        if(i != 0 && a[i] == a[i - 1])
            res -= streak;
        else
            streak = 0;
        ++streak;
    }
    cout << res << endl;
    return 0;
}