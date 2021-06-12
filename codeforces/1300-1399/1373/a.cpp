#include <iostream>

using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(c <= a)
    {
        cout << -1 << " " << b << endl;
    }
    else if(c / (double)b >= a)
    {
        cout << 1 << " " << -1 << endl;
    }
    else
    {
        cout << 1 << " " << b << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
