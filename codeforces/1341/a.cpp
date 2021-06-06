#include <iostream>

#define ll long long

using namespace std;

void solve()
{
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    if((a + b) * n >= c - d && (a - b) * n <= c + d) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
