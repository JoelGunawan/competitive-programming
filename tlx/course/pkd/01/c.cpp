#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    string pre = "", post = "";
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '*')
            break;
        else
            pre += s[i];
    }
    for(int i = s.size() - 1; i >= 0; --i)
    {
        if(s[i] == '*')
            break;
        else
            post += s[i];
    }
    for(int i = 0; i < n; ++i)
    {
        string t;
        cin >> t;
        if(t.size() < pre.size() + post.size())
            continue;
        bool before = 1, after = 1;
        for(int i = 0; i < pre.size(); ++i)
            if(pre[i] != t[i])
                before = 0;
        for(int i = 0; i < post.size(); ++i)
            if(t[t.size() - i - 1] != post[i])
                after = 0;
        if(before && after)
            cout << t << endl;
    }
    string x = "a";
    x += 'b';
    return 0;
}