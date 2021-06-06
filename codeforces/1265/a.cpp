#include <iostream>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    string result = "";
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] != '?')
        {
            if(s[i] == s[i + 1] && i != s.size() - 1)
            {
                cout << "-1" << endl;
                return;
            }
            else result += s[i];
        }
        else
        {
            if((i == 0 || s[i - 1] != 'a') && (i == s.size() - 1 || s[i + 1] != 'a'))
            {
                result += 'a';
                s[i] = 'a';
            }
            else if((i == 0 || s[i - 1] != 'b') && (i == s.size() - 1 || s[i + 1] != 'b'))
            {
                result += 'b';
                s[i] = 'b';
            }
            else
            {
                result += 'c';
                s[i] = 'c';
            }
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
