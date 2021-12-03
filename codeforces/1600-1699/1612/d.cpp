#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#pragma GCC optimize("Ofast")
using namespace std;
bool f(ll a, ll b, ll x)
{
    if(a == x || b == x)
        return 1;
    else if(a == 0 || b == 0 || a == b || (a < x && b < x))
        return 0;
    else
    {
        if(a < b)
            swap(a, b);
        if(a % b == x % b)
            return 1;
        else
            return f(b, a % b, x);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll a, b, x;
        cin >> a >> b >> x;
        if(f(a, b, x))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}