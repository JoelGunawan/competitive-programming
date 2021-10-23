#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string res = "";
    if(s.find('_') == -1)
    {
        // camel case
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] < 'a')
                res += "_", res += (char)(s[i] - 'A' + 'a');
            else
                res += s[i];
        }
    }
    else
    {
        // snake case
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '_')
                res += (char)(s[i + 1] - 'a' + 'A'), ++i;
            else
                res += s[i];
        }
    }
    cout << res << endl;
}