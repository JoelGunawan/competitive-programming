#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        for(int i = 0; i < s.size(); ++i)
        {
            if(i & 1)
                cout << s[i];
            else
                cout << (char)(s[i] + ('A' - 'a'));
        }
        cout << endl;
    }
}