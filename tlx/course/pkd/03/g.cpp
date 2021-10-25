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
    cout << fixed << setprecision(1);
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    if(n % 2 == 0)
        cout << (a[n / 2] + a[n / 2 - 1]) / 2.0 << endl;
    else
        cout << (double)a[n / 2] << endl;
    return 0;
}