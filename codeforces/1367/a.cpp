#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    string result = "";
    for(int i = 0; i < s.size(); ++i)
    {
        if(i % 2 == 0)
            result += s[i];
        else if(i == s.size() - 1)
            result += s[i];
    }
    cout << result << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
