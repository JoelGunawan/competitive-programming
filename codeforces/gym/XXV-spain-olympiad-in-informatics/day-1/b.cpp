#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    vector<int> charcount(26, 0);
    char in;
    for(int i = 0; i < 7; ++i)
        cin >> in, ++charcount[in - 'A'];
    int maxsize = 0;
    for(int i = 0; i < n; ++i)
    {
        if(s[i].size() <= maxsize)
            continue;
        vector<int> localcount(26, 0);
        for(int j = 0; j < s[i].size(); ++j)
            ++localcount[s[i][j] - 'A'];
        bool pos = 1;
        for(int j = 0; j < 26; ++j)
            if(localcount[j] > charcount[j])
                pos = 0;
        if(pos)
            maxsize = s[i].size();
    }
    if(maxsize <= 3)
        cout << maxsize << endl;
    else
        cout << maxsize * 2 << endl;
}