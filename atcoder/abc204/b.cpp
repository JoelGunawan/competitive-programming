#include <bits/stdc++.h>

#define endl "\n"

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    long long res = 0;
    for(int i = 0; i < n; ++i)
        res += max(a[i] - 10, 0);
    cout << res << endl;
    return 0;
}