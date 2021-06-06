#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for(int i = 0; i < 2 * n; ++i)
        cin >> a[i];
    int lastodd = -1, lasteven = -1, result = n - 1;
    for(int i = 0; i < 2 * n; ++i)
    {
        if(result == 0) break;
        if(a[i] & 1)
        {
            if(lastodd == -1)
                lastodd = i;
            else
            {
                --result;
                cout << lastodd + 1 << " " << i + 1 << "\n";
                lastodd = -1;
            }
        }
        else
        {
            if(lasteven == -1)
                lasteven = i;
            else
            {
                --result;
                cout << lasteven + 1 << " " << i + 1 << "\n";
                lasteven = -1;
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
