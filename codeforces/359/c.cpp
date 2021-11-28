#include <bits/stdc++.h>
#define ll long long
//#define endl "\n"
using namespace std;
ll mod = 1e9 + 7;
ll powmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    else
    {
        a %= mod;
        b %= (mod - 1);
        if(b == 0)
            b = mod - 1;
        ll tmp = powmod(a, b / 2); tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x;
    cin >> n >> x;
    ll a[n];
    ll sum = 0;
    for(int i = 0; i < n; ++i)
        cin >> a[i], sum += a[i];
    sort(a, a + n);
    reverse(a, a + n);
    map<ll, int> mp;
    ll least_significant = 2e18;
    for(int i = 0; i < n; ++i)
    {
        ++mp[sum - a[i]];
        least_significant = min(least_significant, sum - a[i]);
        ll cur = sum - a[i];
        while(mp[cur] >= x)
        {
            mp[cur] -= x;
            if(least_significant == cur && mp[cur] == 0)
                ++least_significant;
            ++cur;
            ++mp[cur];
        }
    }
    least_significant = min(least_significant, sum);
    cout << powmod(x, least_significant) << endl;
    return 0;
}