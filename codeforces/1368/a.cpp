#include <iostream>

using namespace std;

void solve()
{
    int a, b, n, res = 0;
    cin >> a >> b >> n;
    if(a > b)
        swap(a, b);
    while(b <= n)
    {
        a += b;
        swap(a, b);
        ++res;
    }
    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
