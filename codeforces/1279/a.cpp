#include <iostream>

#define ll long long

using namespace std;

void solve()
{
    ll r, g, b;
    cin >> r >> g >> b;
    if(2 * max(max(r, g), max(g, b)) - 1 <= r + g + b)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
