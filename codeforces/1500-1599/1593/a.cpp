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
        int a, b, c;
        cin >> a >> b >> c;
        cout << max(a, max(b + 1, c + 1)) - a << " " << max(b, max(a + 1, c + 1)) - b << " " << max(c, max(a + 1, b + 1)) - c << endl;
    }
    return 0;
}