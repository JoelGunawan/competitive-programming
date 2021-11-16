#include <bits/stdc++.h>
#define ll long long
using namespace std;
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    ll res = lcm(a, b);
    cout << res / a + res / b << endl;
    return 0;
}