#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    // find first one and last zero, all occurences in that span can be "destroyed" and become one '0'
    int firstone = n, lastzero = -1;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '0')
            lastzero = i;
        else
            firstone = min(firstone, i);
    }
    for(int i = 0; i < firstone; ++i)
        cout << s[i];
    if(firstone > lastzero)
        lastzero = firstone;
    for(int i = lastzero; i < n; ++i)
        cout << s[i];
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
