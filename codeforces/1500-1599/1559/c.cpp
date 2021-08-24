#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        if(a[0] == 1)
        {
            cout << n + 1;
            for(int i = 1; i <= n; ++i)
                cout << " " << i;
            cout << endl;
            continue;
        }
        else if(a[n - 1] == 0)
        {
            for(int i = 1; i <= n + 1; ++i)
                cout << i << " ";
            cout << endl;
            continue;
        }
        else
        {
            cout << 1;
            bool done = 0;
            for(int i = 1; i < n; ++i)
            {
                if(a[i - 1] == 0 && a[i] == 1 && !done)
                {
                    // go to n + 1
                    cout << " " << n + 1;
                    done = 1;
                }
                cout << " " << i + 1;
            }
            cout << endl;
        }
    }
    return 0;
}