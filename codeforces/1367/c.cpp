#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int last = -1, result = 0;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '1')
        {
            if(last == -1)
                result += max(0, (int)ceil((i - k) / (double)(k + 1)));
            else
                result += max(0, (int)ceil((i - last - 2 * k - 1) / (double)(k + 1)));
            last = i;
        }
    }
    //cout << result << " " << last << endl;
    if(last == -1)
        result += max(0, (int)ceil(n / (double)(k + 1)));
    else
        result += max(0, (int)ceil((n - k - last - 1) / (double)(k + 1)));
    cout << result << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
