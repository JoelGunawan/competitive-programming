#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}
 
ll f(ll a, ll b)
{
    if(a > b) return a;
    else return b;
}
 
void solve()
{
    ll p, q;
    cin >> p >> q;
    if(p % q != 0) cout << p;
    else if(p == q)
    {
        int res = 1;
        for(int i = 2; i <= sqrt(p); ++i)
        {
            if(p % i == 0)
            {
                res = p / i;
                break;
            }
        }
        cout << res;
    }
    else
    {
        ll a = gcd(p, q);
        vector<int> primes;
        ll b = a;
        for(int i = 2; i <= sqrt(a); ++i)
        {
            if(b % i == 0)
            {
                while(b % i == 0) b /= i;
                primes.push_back(i);
            }
        }
        if(b > 1) primes.push_back(b);
        ll res = 0;
        for(int i = 0; i < primes.size(); ++i)
        {
            ll tmp = p;
            while(tmp % q == 0)
            {
                tmp /= primes[i];
            }
            res = f(res, tmp);
        }
        cout << res;
    }
    cout << endl;
}
 
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}