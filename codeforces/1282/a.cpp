#include <iostream>

using namespace std;

void solve()
{
    int a, b, c, r;
    cin >> a >> b >> c >> r;
    if(max(a, b) >= c && min(a, b) <= c)
    {
        cout << abs(a - b) - (min(c + r, max(a, b)) - max(c - r, min(a, b))) << endl;
    }
    else if(c >= max(a, b))
    {
        cout << abs(a - b) - (max(a, b) - min(max(c - r, min(a, b)), max(a, b))) << endl;
    }
    else
    {
        cout << abs(a - b) - (max(min(c + r, max(a, b)), min(a, b)) - min(a, b)) << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
