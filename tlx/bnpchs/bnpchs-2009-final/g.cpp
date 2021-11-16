#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
ll mod = 1000000007;
ll powmod(ll x, ll y)
{
    if(y == 0)
        return 1;
    else
    {
        ll tmp = powmod(x, y / 2);
        if(y & 1)
            return (((tmp * tmp) % mod) * x) % mod;
        else
            return (tmp * tmp) % mod;
    }
}
void test_case()
{
    ll a, b;
    cin >> a >> b;
    // do for each factor of a
    vector<pair<int, int>> factors;
    for(int i = 2; i <= sqrt(a); ++i)
    {
        if(a % i == 0)
        {
            int tmp = 0;
            while(a % i == 0)
            {
                a /= i;
                ++tmp;
            }
            factors.push_back(make_pair(i, tmp));
        }
    }
    if(a > 1)
        factors.push_back(make_pair(a, 1));
    ll res = 1;
    for(int i = 0; i < factors.size(); ++i)
    {
        res = (res * (powmod(factors[i].first, factors[i].second * b + 1) - 1)) % mod;
        res = (res * powmod(factors[i].first - 1, mod - 2)) % mod;
    }
    if(res < 0)
        res += mod;
    if(b == 0)
        cout << 1 << endl;
    else if(a == 0)
        cout << 0 << endl;
    else
        cout << res << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
        test_case();
}