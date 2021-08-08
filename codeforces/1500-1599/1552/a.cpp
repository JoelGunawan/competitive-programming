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
        int n, res = 0; string s;
        cin >> n >> s;
        string t = s;
        sort(t.begin(), t.end());
        for(int i = 0; i < n; ++i)
        {
            if(s[i] != t[i])
                ++res;
        }
        cout << res << endl;
    }
    return 0;
}