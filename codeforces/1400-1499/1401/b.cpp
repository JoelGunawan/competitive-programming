#include <iostream>
 
using namespace std;
 
void solve()
{
    int a, b, c, x, y, z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    int sum = 0;
    int tmp = min(c, y);
    sum += tmp;
    c -= tmp;
    y -= tmp;
    tmp = min(c, z);
    c -= tmp;
    z -= tmp;
    tmp = min(c, x);
    c -= tmp;
    x -= tmp;
    tmp = min(a, z);
    a -= tmp;
    z -= tmp;
    tmp = min(a, y);
    a -= tmp;
    y -= tmp;
    tmp = min(a, x);
    a -= tmp;
    x -= tmp;
    tmp = min(b, x);
    b -= tmp;
    x -= tmp;
    tmp = min(b, y);
    b -= tmp;
    y -= tmp;
    tmp = min(b, z);
    sum -= tmp;
    cout << sum * 2 << endl;
}
 
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}