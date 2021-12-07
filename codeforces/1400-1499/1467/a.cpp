#include <bits/stdc++.h>
 
using namespace std;
 
string f(int n)
{
    if(n == 0) return "";
    string s = "";
    const string t = "0123456789";
    while(n > 10)
    {
        n -= 10;
        s += t;
    }
    s += t.substr(0, n);
    return s;
}
 
void solve()
{
    int n;
    cin >> n;
    if(n == 1) cout << 9 << endl;
    else if(n == 2) cout << 98 << endl;
    else
    {
        cout << 989;
        n -= 3;
        cout << f(n) << endl;
    }
}
 
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}