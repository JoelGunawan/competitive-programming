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
        int n;
        cin >> n;
        pair<int, int> a[n];
        int in;
        for(int i = 0; i < n; ++i)
            cin >> in, a[i] = mp(in, i + 1);
        sort(a, a + n);
        reverse(a, a + n);
        int coords[n + 1];
        coords[0] = 0;
        ll res = 0;
        for(int i = 0; i < n; ++i) {
            if(i % 2 == 0)
                coords[a[i].se] = i / 2 + 1;
            else
                coords[a[i].se] = -(i / 2 + 1);
            res += 1ll * (i / 2 + 1) * a[i].fi * 2;
        }
        cout << res << endl;
        for(int i = 0; i <= n; ++i)
            cout << coords[i] << " ";
        cout << endl;
    }
    return 0;
}