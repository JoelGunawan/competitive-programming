#include <iostream>

using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;
    if(x >= y || x > 3 || (x == 2 && y == 3)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
