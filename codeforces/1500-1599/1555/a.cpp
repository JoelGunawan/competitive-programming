#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pb push_back
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll res;
        if(n < 6)
            res = 15;
        else
            res = (n + n % 2) / 2 * 5;
        cout << res << endl;
    }
    return 0;
}