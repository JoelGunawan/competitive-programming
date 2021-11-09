#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define ins insert
#define endl "\n"
#define lb lower_bound
#define ub upper_Bound
#define mp make_pair
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    fast_io();
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int prefix[n + 1];
    prefix[0] = 0;
    for(int i = 1; i <= n; ++i)
        prefix[i] = prefix[i - 1] + (s[i - 1] - '0');
    ll res = 0;
    for(int i = 1; i <= n; ++i)
    {
        // determine if we need to add
        if(prefix[min(i + k, n)] - prefix[max(i - k - 1, 0)] == 0)
            res += i;
    }
    for(int i = 0; i < n; ++i)
    {   
        if(s[i] == '1')
        {
            res += (i + 1);
            if(i + k == n - 1)
                break;
        }
    }
    cout << res << endl;
    return 0;
}