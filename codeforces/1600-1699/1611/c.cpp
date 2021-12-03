#include <bits/stdc++.h>
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pf push_front
#define ll long long
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        if(a[0] != n && a[n - 1] != n)
            cout << -1 << endl;
        else
        {
            if(a[0] == n)
                reverse(a + 1, a + n);
            else
                reverse(a, a + n - 1);
            for(int i = 0; i < n; ++i)
                cout << a[i] << " ";
            cout << endl;
        }
    }
    return 0;
}