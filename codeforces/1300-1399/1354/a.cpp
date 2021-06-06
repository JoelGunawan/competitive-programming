#include <iostream>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(b >= a) cout << b << endl;
    else if(d >= c) cout << -1 << endl;
    else
    {
        ll n = ceil((a - b) / (double)(c - d)) * c + b;
        cout << n << endl;
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
