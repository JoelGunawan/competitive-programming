#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define ins insert
#define endl "\n"
#define lb lower_bound
#define ub upper_Bound
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    fast_io();
    int t;
    cin >> t;
    while(t--)
    {
        map<int, int> mp;
        int n;
        cin >> n;
        int input;
        for(int i = 0; i < n; ++i)
            cin >> input, mp[input - i]++; // cout << input - i << " ";
        //cout << endl;
        ll res = 0;
        for(int i = -n - 1; i <= n + 1; ++i)
            res += mp[i] * 1ll * (mp[i] - 1) / 2;
        cout << res << endl;
    }
    return 0;
}