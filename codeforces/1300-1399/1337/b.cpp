#include <iostream>

using namespace std;

void solve()
{
    int h, n, m;
    cin >> h >> n >> m;
    while(h > 20 && n--)
    {
        h = h / 2 + 10;
    }
    if(h - m * 10 <= 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
