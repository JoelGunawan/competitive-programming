#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int oddCount = 0;
    for(int i = 0; i < n; ++i)
    {
        if((s[i] - '0') % 2 == 1) oddCount++;
    }
    if(oddCount < 2) cout << -1 << endl;
    else
    {
        string result = "";
        for(int i = 0; i < n; ++i)
        {
            if((s[i] - '0') % 2 == 1) result += s[i];
            if(result.size() % 2 == 0 && result.size() != 0)
            {
                cout << result << endl;
                break;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
