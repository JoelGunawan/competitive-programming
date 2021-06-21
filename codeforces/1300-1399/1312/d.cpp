#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int mod = 998244353;
ll power(ll x, ll y)
{
    if(y == 0)
        return 1;
    else
    {
        ll tmp = power(x, y / 2);
        tmp = (tmp * tmp) % mod;
        if(y & 1)
            tmp = (tmp * x) % mod;
        return tmp;
    }
}

ll c(ll x, ll y)
{
    if(x < y) return 0;
    ll res = 1;
    for(int i = x; i > max(y, x - y); --i)
        res = (res * i) % mod;
    for(int i = 2; i <= min(y, x - y); ++i)
        res = (res * power(i, mod - 2)) % mod;
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    if(n == 2)
        cout << 0 << endl;
    else
        cout << (((n - 2) * c(m, n - 1)) % mod * power(2, n - 3)) % mod << endl;
}