#include <iostream>
#include <cmath>

using namespace std;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int min1 = min(a, b), max1 = max(a, b), min2 = min(c, d), max2 = max(c, d);
    if(max1 == max2 && min1 + min2 == max1)
    {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
