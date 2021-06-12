#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s, t;
        cin >> s >> t;
        // check whether it is possible or not
        vector<set<int>> a(26, set<int>());
        for(int i = 0; i < s.size(); ++i)
            a[s[i] - 'a'].insert(i);
        vector<bool> exists(26, 0);
        for(int i = 0; i < t.size(); ++i)
            exists[t[i] - 'a'] = 1;
        bool possible = 1;
        for(int i = 0; i < exists.size(); ++i)
            if(exists[i] && a[i].size() == 0)
            {
                possible = 0;
                break;
            }
        if(!possible)
        {
            cout << -1 << endl;
            continue;
        }
        int currentIndex = -1, x, res = 1;
        for(int i = 0; i < t.size(); ++i)
        {
            x = t[i] - 'a';
            if(a[x].upper_bound(currentIndex) == a[x].end())
            {
                currentIndex = *a[x].begin();
                ++res;
            }
            else
                currentIndex = *a[x].upper_bound(currentIndex);
        }
        cout << res << endl;
    }
}