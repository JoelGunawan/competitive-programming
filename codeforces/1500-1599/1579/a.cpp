#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    string s; int a, b, c;
    while(t--)
    {
        cin >> s;
        a = b = c = 0;
        for(int i = 0; i < s.size(); ++i)
            if(s[i] == 'A')
                ++a;
            else if(s[i] == 'B')
                ++b;
            else
                ++c;
        if(b == a + c)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}