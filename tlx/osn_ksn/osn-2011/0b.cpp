#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    if(s[0] == s[1])
    {
        for(int i = 0; i < 8; ++i)
            if(s[i] != s[0])
                cout << i + 1 << endl;
    }
    else if(s[0] == s[7])
        cout << 2 << endl;
    else
        cout << 1 << endl;
    return 0;
}