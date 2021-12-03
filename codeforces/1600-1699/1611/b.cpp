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
        int a, b;
        cin >> a >> b;
        cout << min((a + b) / 4, min(a, b)) << endl;
    }
    return 0;
}