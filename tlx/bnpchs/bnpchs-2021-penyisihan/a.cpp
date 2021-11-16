#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int oddstreak = 0, oddres = 0, evenstreak = 0, evenres = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(i & 1)
        {
            if(s[i] == 'z')
                ++oddstreak, evenres = max(evenres, evenstreak), evenstreak = 0;
            else
                ++evenstreak, oddres = max(oddres, oddstreak), oddstreak = 0;
        }
        else
        {
            if(s[i] == 'z')
                ++evenstreak, oddres = max(oddres, oddstreak), oddstreak = 0;
            else
                ++oddstreak, evenres = max(evenres, evenstreak), evenstreak = 0;
        }
    }
    oddres = max(oddres, oddstreak), evenres = max(evenres, evenstreak);
    cout << max(oddres, evenres) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}