#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    long long res = 0, cur = 0;
    for(int i = 0; i <= m; ++i)
        cur += a[i];
    res = cur;
    for(int i = m + 1; i < n; ++i)
        cur -= a[i - (m + 1)], cur += a[i], res = max(res, cur);
    cout << res << endl;
    return 0;
}