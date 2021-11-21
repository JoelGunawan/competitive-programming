#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, l, r;
    cin >> n >> l >> r;
    ll res = 0;
    for(ll i = 0; i < 63; ++i)
    {
        if((1ll << i) > r)
            break;
        else if(n & (1ll << i))
            res += max(0ll, min(r, (1ll << (i + 1ll)) - 1ll) - max(l, (1ll << i)) + 1ll); 
    }
    cout << res << endl;
    return 0;
}