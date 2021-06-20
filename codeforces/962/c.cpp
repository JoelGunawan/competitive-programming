#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    // make all subsequences of n
    string ans = "";
    for(int i = 1; i < (1 << s.size()); ++i)
    {
        string t;
        for(int j = 0; j < s.size(); ++j)
            if(i & (1 << j))
                t += s[j];
        if(t[0] == '0')
            continue;
        int a = stoi(t);
        if(sqrt(a) == (int)sqrt(a) && t.size() > ans.size())
            ans = t;
    }
    if(ans.size() == 0) 
        cout << -1 << endl;
    else
        cout << s.size() - ans.size() << endl;
    return 0;
}