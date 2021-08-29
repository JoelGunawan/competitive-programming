#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> differences(n - 1);
    for(int i = 0; i < n - 1; ++i)
        differences[i] = a[i + 1] - a[i];
    sort(differences.begin(), differences.end(), greater<int>());
    ll res = 0;
    for(int i = k - 1; i < n - 1; ++i)
        res += differences[i];
    cout << res << endl;
    return 0;
}