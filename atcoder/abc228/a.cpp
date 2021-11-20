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
    int s, t, x;
    cin >> s >> t >> x;
    while(s != t)
    {
        if(x == s)
        {
            cout << "Yes" << endl;
            return 0;
        }
        s = (s + 1) % 24;
    }
    cout << "No" << endl;
    return 0;
}