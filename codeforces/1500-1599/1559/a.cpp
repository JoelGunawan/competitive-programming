#include <bits/stdc++.h>
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
        int res = a[0];
        for(int i = 1; i < n; ++i)
            res &= a[i];
        cout << res << endl;
    }
}