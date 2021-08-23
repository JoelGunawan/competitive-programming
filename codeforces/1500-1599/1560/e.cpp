#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        string t;
        cin >> t;
        string s = "";
        vector<bool> used(26, 0);
        for(int i = t.size() - 1; i >= 0; --i)
            if(!used[t[i] - 'a'])
                s += t[i], used[t[i] - 'a'] = 1;
        vector<int> a(s.size(), 0);
        for(int i = 0; i < s.size(); ++i)
            for(int j = 0; j < t.size(); ++j)
                if(s[i] == t[j])
                    ++a[i];
        // check for validity, we first check count
        bool valid = 1;
        for(int i = 0; i < a.size(); ++i)
        {
            if(a[i] % (s.size() - i) != 0)
                valid = 0;
            else
                a[i] /= (s.size() - i);
        }
        if(!valid)
        {
            cout << -1 << endl;
            continue;
        }
        reverse(s.begin(), s.end()); reverse(a.begin(), a.end());
        int sum = 0, current = 0;
        for(int i = 0; i < a.size(); ++i)
            sum += a[i];
        string previous = t.substr(0, sum);
        // just build the string?
        string x = "";
        for(int i = 0; i < s.size(); ++i)
        {
            x += previous;
            string tmp = "";
            for(int j = 0; j < previous.size(); ++j)
                if(previous[j] != s[i])
                    tmp += previous[j];
            previous = tmp;
        }
        if(x == t)
            cout << t.substr(0, sum) << " " << s << endl;
        else    
            cout << -1 << endl;
    }
}