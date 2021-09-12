#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ins insert
#define pf push_front
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n], b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    if(n <= 1000 && m <= 1000)
    {
        // do n^2 algo
        ll res = 0;
        for(int i = 0; i < m; ++i)
        {
            ll local = 0;
            for(int j = 0; j < n; ++j)
                local += ((a[j] + i) % m) * (ll)b[j];
            res = max(res, local);
        }
        cout << res << endl;
    }
    else
    {
        // do subtask 1
        ll sum = 0;
        for(int i = 0; i < n; ++i)
            sum += b[i];
        cout << sum * (m - 1) << endl;
    }
    return 0;
}