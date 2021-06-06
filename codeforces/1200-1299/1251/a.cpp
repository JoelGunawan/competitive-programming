#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<bool> hasOdd(26, false);
    vector<int> counter(26, 0);
    int subsequence = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        ++counter[s[i] - 'a'];
        if(i != 0 && s[i - 1] != s[i])
        {
            if(subsequence % 2 == 1)
            {
                hasOdd[s[i - 1] - 'a'] = true;
            }
            subsequence = 0;
        }
        ++subsequence;
    }

    if(subsequence % 2 == 1)
    {
        hasOdd[s[s.size() - 1] - 'a'] = true;
    }

    string result = "";
    for(int i = 0; i < 26; ++i)
    {
        if(hasOdd[i] || counter[i] % 2 == 1)
        {
            result += ('a' + i);
        }
    }
    cout << result << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
