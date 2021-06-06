#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b, n;
    cin >> a >> b >> n;
    if(n % 3 == 0)
    {
        cout << a << endl;
    }
    else if(n % 3 == 1)
    {
        cout << b << endl;
    }
    else
    {
        cout << (a ^ b) << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
