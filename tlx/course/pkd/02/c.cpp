#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
    /*
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
    */
}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
int main()
{
    int n, res, in;
    cin >> n >> res;
    for(int i = 0; i < n - 1; ++i)
        cin >> in, res = lcm(res, in);
    cout << res << endl;
    return 0; 
}