#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll e = a * d + b * c, f = b * d, fpb = gcd(e, f);
    cout << e / fpb << " " << f / fpb << endl;
    return 0;
}