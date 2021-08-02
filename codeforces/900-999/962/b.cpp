#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b; string s;
    cin >> n >> a >> b >> s;
    int streak = 0; multiset<int> lengths;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '*')
        {
            lengths.insert(streak);
            streak = 0;
        }
        else
            ++streak;
    }
    if(streak > 0)
    lengths.insert(streak);
    while(lengths.size() > 0 && *lengths.begin() == 0)
        lengths.erase(lengths.begin());
    int res = 0;
    for(auto it = lengths.begin(); it != lengths.end(); ++it)
    {
        if(*it & 1)
        {
            if(a > b)
            {
                res += min(a, *it / 2 + 1) + min(b, *it / 2);
                a -= min(a, *it / 2 + 1);
                b -= min(b, *it / 2);
            }
            else
            {
                res += min(a, *it / 2) + min(b, *it / 2 + 1);
                a -= min(a, *it / 2);
                b -= min(b, *it / 2 + 1);
            }
        }
        else
        {
            res += min(a, *it / 2) + min(b, *it / 2);
            a -= min(a, *it / 2);
            b -= min(b, *it / 2);
        }
    }
    cout << res << endl;
    return 0;
}