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
        long long res = 0;
        for(int i = 0; i < n - 1; ++i)
            res = max(res, (long long)a[i] * a[i + 1]);
        cout << res << endl;
    }
}