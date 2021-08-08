#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    string ref = "abcdefghijklmnopqrstuvwxyz";
    while(t--)
    {
        string s, x, ans = "YES";
        cin >> s;
        x = s;
        sort(x.begin(), x.end());
        for(int i = 0; i < s.size(); ++i)
            if(ref[i] != x[i])
                ans = "NO";
        int origin;
        for(int i = 0; i < s.size(); ++i)
            if(s[i] == 'a')
                origin = i;
        for(int i = 0; i < origin - 1; ++i)
            if(s[i] <= s[i + 1])
                ans = "NO";
        for(int i = origin + 1; i < s.size() - 1; ++i)
            if(s[i] >= s[i + 1])
                ans = "NO";
        cout << ans << endl;
    }
    return 0;
}