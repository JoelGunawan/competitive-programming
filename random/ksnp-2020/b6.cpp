#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7;
ll pow(ll a, ll b)
{
    ll res = 1;
    for(int i = 0; i < b; ++i)
        res = (res * a) % mod;
    return res;
}
int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    if(n % k)
        cout << 0 << endl;
    else
        cout << pow(m, n / k) << endl;
    return 0;
}