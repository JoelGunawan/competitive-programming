#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
int mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    ll res = 1, memo = res;
    for(int i = 2; i <= n; ++i)
        res = (res * i) % mod;
    cout << res << endl;
    return 0;
}