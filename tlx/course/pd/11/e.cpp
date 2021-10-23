#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] < 'a')
            s[i] = (s[i] - 'A') + 'a';
        else
            s[i] = (s[i] - 'a') + 'A';
    }
    cout << s << endl;
    return 0;
}