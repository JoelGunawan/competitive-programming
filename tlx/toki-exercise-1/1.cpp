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
        reverse(s.begin(), s.end());
        int start = 0;
        while(start != s.size() - 1 && s[start] == '0')
            ++start;
        for(int i = start; i < s.size(); ++i)
            cout << s[i];
        cout << endl;
    }
}