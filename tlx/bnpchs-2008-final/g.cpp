#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a, a + n);
        long long res = 0;
        for(int i = 0; i < n; ++i)
            res += (abs(a[i] - (i + 1)));
        cout << res << endl;
    }
    return 0;
}