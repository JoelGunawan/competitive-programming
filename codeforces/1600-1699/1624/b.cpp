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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        vector<ll> a(3);
        cin >> a[0] >> a[1] >> a[2];
        //cout << a[1] - a[0] << " " << a[2] - a[1] << endl;
        //cout << 2 * a[1] - a[0] << " " << 2 * a[2] - a[0] << " " << 2 * a[2] - a[1] << endl;
        if(a[1] - a[0] == a[2] - a[1]
        || ((a[0] + a[2]) % 2 == 0 && ((a[0] + a[2]) / 2) % a[1] == 0)
        || (2 * a[1] - a[2] >= a[0] && (2 * a[1] - a[2]) % a[0] == 0)
        || (2 * a[1] - a[0] >= a[2] && (2 * a[1] - a[0]) % a[2] == 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}