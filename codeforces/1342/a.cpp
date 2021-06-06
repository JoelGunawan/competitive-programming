#include <iostream>

#define ull unsigned long long

using namespace std;

void solve()
{
    ull x, y, a, b;
    cin >> x >> y;
    cin >> a >> b;
    if(a * 2 <= b)
    {
        cout << (x + y) * a << endl;;
    }
    else
    {
        cout << ((ull)min(x, y) * b) + ((ull)abs((long long)x - (long long)y) * a) << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
