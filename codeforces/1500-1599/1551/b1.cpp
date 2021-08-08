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
        vector<int> counter(26, 0);
        for(int i = 0; i < s.size(); ++i)
            counter[s[i] - 'a'] = min(2, counter[s[i] - 'a'] + 1);
        int res = 0;
        for(int i = 0; i < 26; ++i)
            res += counter[i];
        cout << res / 2 << endl;
    }
    return 0;
}