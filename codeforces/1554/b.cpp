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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        int l = max(0, n - 2 * k - 1);
        long long res = LONG_LONG_MIN;
        for(int i = l; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                res = max((i + 1) * (long long)(j + 1) - k * (a[i] | a[j]), res);
        cout << res << endl;
    }
    return 0;
}