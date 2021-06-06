#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

bool isPowerOf2(ll a)
{
    if(a == 1 || a == 2) return true;
    else if(a % 2 == 1) return false;
    else return isPowerOf2(a / 2);
}

ll findGcd(ll a, ll b)
{
    if(b == 0) return a;
    else return findGcd(b, a % b);
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    ll gcd = findGcd(a, b);
    if(isPowerOf2(a / gcd) && isPowerOf2(b / gcd))
    {
        cout << ceil(abs(log2(a / gcd) - log2(b / gcd)) / 3.0) << endl;
    }
    else cout << -1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
