#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int mod = 1e9 + 7;
vector<ll> arr;
ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    else 
        return gcd(b, a % b);
}
void generatelcm(ll num)
{
    ll res = 2;
    int i = 3;
    while(res <= num)
    {
        res = res / gcd(res, i) * i;
        ++i;
        arr.push_back(res);
    }
    return;
}
void test_case()
{
    ll n;
    cin >> n;
    ll res = (n / 2) * 3 + (n / 2 + n % 2) * 2;
    res %= mod;
    for(int i = 0; i < arr.size() && arr[i] <= n; ++i)
        res = (res + n / arr[i]) % mod;
    cout << res << endl;
}
int main()
{
    generatelcm(1e16);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}