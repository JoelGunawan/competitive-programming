#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s, t;
        cin >> s >> t;
        int a = 0;
        bool ans = 0;
        for(int i = s.size() - 1; i >= 0; --i)
        {
            if(s[i] == t[t.size() - a - 1])
                ++a;
            else
                --i;
            if(a == t.size())
            {
                ans = 1;
                break;
            }
        }
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}