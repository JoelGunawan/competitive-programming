#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    fast_io();
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int q;
    cin >> q;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        cout << upper_bound(a, a + n, y) - upper_bound(a, a + n, x) << endl;
    }
    return 0;
}