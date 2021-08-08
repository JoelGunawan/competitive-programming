#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void test_case()
{
    string s;
    cin >> s;
    int n = s.size();
    long long res = 0, questionStreak = 0, curLen = 0, curState;
    if(s[0] == '?')
        curState = -1;
    else if(s[0] == '0')
        curState = 1;
    else
        curState = 0;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '?')
        {
            ++questionStreak;
            if(curState == 0)
                curState = 1;
            else if(curState == 1)
                curState = 0;
        }
        else if(s[i] == '0')
        {
            if(curState == 0)
            {
                // reset
                res += curLen * (curLen + 1) / 2 - (questionStreak * (questionStreak + 1) / 2);
                curLen = questionStreak;
            }
            questionStreak = 0;
            curState = 0;
        }
        else
        {
            if(curState == 1)
            {
                // reset
                res += curLen * (curLen + 1) / 2 - (questionStreak * (questionStreak + 1) / 2);
                curLen = questionStreak;
            }
            questionStreak = 0;
            curState = 1;
        }
        ++curLen;
    }
    res += curLen * (curLen + 1) / 2;
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}