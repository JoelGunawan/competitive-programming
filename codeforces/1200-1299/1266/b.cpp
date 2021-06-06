#include <iostream>

#define ll long long

using namespace std;

void solve()
{
    ll n;
    cin >> n;
    if(n % 14 > 6 || n < 15 || n % 14 == 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
