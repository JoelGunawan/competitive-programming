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
    vector<int> a(n), c(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> c[i];
    // use the two pointers approach
    int pointer = 0; ll res = 0;
    vector<ll> prefix(n + 1, 0);
    for(int i = 0; i < n; ++i)
        prefix[i + 1] = prefix[i] + c[i];
    for(int i = 0; i < n; ++i)
    {
        while(pointer + 1 < n && (a[pointer + 1] - a[i]) <= k)
        {
            res = max(res, prefix[pointer + 1] - prefix[i] + k - (a[pointer] - a[i]));
            ++pointer;
        }
        res = max(res, prefix[pointer + 1] - prefix[i] + k - (a[pointer] - a[i]));
    }
    cout << res << endl;
    return 0;
}