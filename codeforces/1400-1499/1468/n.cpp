#include <bits/stdc++.h>
 
using namespace std;
 
void solve()
{
    int c1, c2, c3, a1, a2, a3, a4, a5;
    cin >> c1 >> c2 >> c3;
    cin >> a1 >> a2 >> a3 >> a4 >> a5;
    c1 -= a1;
    c2 -= a2;
    c3 -= a3;
    a4 -= max(min(c1, a4), 0);
    a5 -= max(min(c2, a5), 0);
    c3 = c3 - a4 - a5;
    if(c1 < 0 || c2 < 0 || c3 < 0)
    {
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;
}
 
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}