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
        int n = s.size();
        bool ans[26]; memset(ans, 0, sizeof(ans));
        for(int i = 0; i < n; ++i)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
                ans[s[i] - 'a'] = 1;
        }
        int res = 0;
        for(int i = 0; i < 26; ++i)
            res += ans[i];
        cout << res << endl;
    }
    return 0;
}