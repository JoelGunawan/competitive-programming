#include <bits/stdc++.h>
 
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for(int i = 1; i < n; ++i)
    {
        if(s[i] == s[i - 1])
        {
            if(s[i] == '0') ++a;
            else ++b;
        }
    }
    cout << max(a, b) << endl;
}
 
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}