#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define lll __int128
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
void test_case()
{
    ll n, m;
    cin >> n >> m;
    if(n == 1 || m == 1)
        cout << -1 << endl;
    else if(n % 2 == 0 && m % 2 == 0)
        cout << n * m / 4 << endl;
    else if(n % 2 == 0 || m % 2 == 0)
    {
        if(n % 2 == 0)
            cout << (m - 3) * n / 4 << endl;
        else
            cout << (n - 3) * m / 4 << endl;
    }
    else
    {
        if(n == 3 || m == 3 || n * m % 3 != 0)
            cout << -1 << endl;
        else
            cout << 0 << endl;
    }
}
int main()
{
    fast_io();
    test_case();
    return 0;
}