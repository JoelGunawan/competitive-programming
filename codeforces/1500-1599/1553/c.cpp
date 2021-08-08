#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int minteam1 = 0, maxteam1 = 0, minteam2 = 0, maxteam2 = 0;
        for(int i = 0; i < 3; ++i)
        {
            if(s[2 * i] == '?')
                ++maxteam1;
            else if(s[2 * i] == '1')
            {
                ++minteam1;
                ++maxteam1;
            }
            if(s[2 * i + 1] == '?')
                ++maxteam2;
            else if(s[2 * i + 1] == '1')
            {
                ++minteam2;
                ++maxteam2;
            }
        }
        if(maxteam1 - minteam2 > 2 || maxteam2 - minteam1 > 2)
        {
            cout << 6 << endl;
            continue;
        }
        if(s[6] == '1')
        {
            ++maxteam1;
            ++minteam1;
        }
        else if(s[6] == '?')
            ++maxteam1;
        if(maxteam1 - minteam2 > 2 || maxteam2 - minteam1 > 1)
        {
            cout << 7 << endl;
            continue;
        }
        if(s[7] == '1')
        {
            ++maxteam2;
            ++minteam2;
        }
        else if(s[7] == '?')
            ++maxteam2;
        if(maxteam2 - minteam1 > 1 || maxteam1 - minteam2 > 1)
        {
            cout << 8 << endl;
            continue;
        }
        if(s[8] == '1')
        {
            ++maxteam1;
            ++minteam1;
        }
        else if(s[8] == '?')
            ++maxteam1;
        //cout << maxteam1 << " " << minteam1 << " " << maxteam2 << " " << minteam2 << endl;
        if(maxteam1 - minteam2 > 1 || maxteam2 - minteam1 > 0)
            cout << 9 << endl;
        else
            cout << 10 << endl;
    }
    return 0;
}