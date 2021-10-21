#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        cout << n / 4 * (n / 4 + 1) / 2 * 4 + n / 7 * (n / 7 + 1) / 2 * 7 - n / 28 * (n / 28 + 1) / 2 * 28 << endl;
    }
}