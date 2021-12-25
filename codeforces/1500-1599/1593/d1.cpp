// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        int x = 0;
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                x = gcd(x, abs(a[j] - a[i]));
        if(x == 0)
            cout << -1 << endl;
        else
            cout << x << endl;
    }
    return 0;
}