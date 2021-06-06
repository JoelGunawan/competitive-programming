#include <bits/stdc++.h>

using namespace std;

void tc()
{
    string s;
    cin >> s;
    s = "R" + s + "R";
    int n = s.size();
    // find the maximum between 2 R's
    int cur = 0, maxLen = 0;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == 'R')
        {
            maxLen = max(cur, maxLen);
            cur = 0;
        }
        else
            ++cur;
    }
    cout << maxLen + 1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}
