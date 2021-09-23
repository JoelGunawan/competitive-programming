#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; string s, res;
    bool used[256];
    cin >> t;
    while(t--)
    {
        res = "", memset(used, 0, sizeof(used));
        cin >> s;
        for(int i = 0; i < s.size(); ++i)
            if(!used[(int)s[i]])
                used[(int)s[i]] = 1, res += s[i];
        cout << res << endl;
    }
}