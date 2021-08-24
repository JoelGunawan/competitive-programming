#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int first = -1;
        for(int i = 0; i < n; ++i)
            if(s[i] != '?')
            {
                first = i;
                break;
            }
        if(first == -1)
        {
            for(int i = 0; i < n; ++i)
            {
                if(i & 1)
                    cout << 'B';
                else
                    cout << 'R';
            }
            cout << endl;
            continue;
        }
        // do before first and after first
        for(int i = first - 1; i >= 0; --i)
        {
            if(first % 2 == i % 2)
                s[i] = s[first];
            else
            {
                if(s[first] == 'B')
                    s[i] = 'R';
                else
                    s[i] = 'B';
            }
        }
        for(int i = first + 1; i < n; ++i)
        {
            if(s[i] == '?')
            {
                if(s[i - 1] == 'R')
                    s[i] = 'B';
                else
                    s[i] = 'R';
            }
        }
        cout << s << endl;
    }
}