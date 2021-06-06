#include <iostream>

#define ll long long

using namespace std;

void solve()
{
    ll x, y;
    cin >> x >> y;
    if(x - y > 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
