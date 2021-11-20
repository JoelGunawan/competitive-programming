#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    int p[n], a[n];
    for(int i = 0; i < n; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        p[i] = -(x + y + z);
        a[i] = p[i] - 300;
    }
    sort(p, p + n);
    for(int i = 0; i < n; ++i)
    {
        int rank = lower_bound(p, p + n, a[i]) - p + 1;
        if(rank <= k)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}