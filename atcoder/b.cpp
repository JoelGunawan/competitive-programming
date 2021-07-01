#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == 0 && b / c == d)
        cout << 0 << endl;
    else if(b / c >= d)
        cout << -1 << endl;
    // basically (a + k * b) / (k * c) <= d
    // a + k * b <= k * c * d
    // find the minimum k value
    else
    {
        int k = 1;
        while(k * c * d < a + k * b)
            ++k;
        cout << k << endl;
    }
}