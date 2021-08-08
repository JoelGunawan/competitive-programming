#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string rev(string a)
{
    reverse(a.begin(), a.end());
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q;
    cin >> q;
    while(q--)
    {
        string s, t;
        cin >> s >> t;
        bool done = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            // do every possible substring and check with t
            string a = "";
            for(int j = i; j < s.size(); ++j)
            {
                a += s[j];
                if(a.size() > t.size())
                    break;
                else if(j >= t.size() - a.size() && a + rev(s.substr(j - (t.size() - a.size()), (t.size() - a.size()))) == t)
                    done = 1;
            }
            if(done)
                break;
        }
        if(!done)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}