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
void tc() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> a(n);
    for(int i = 0; i < n; ++i) {
        int l, r, c;
        cin >> l >> r >> c;
        a[i] = mp(mp(l, r), c);
    }
    // choose 3 segments
    // longest segment (with least cost)
    // most left (with least cost)
    // most right (with least cost)
    int mr = 0, ml = 0, ls = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i].fi.se > a[mr].fi.se || (a[i].fi.se == a[mr].fi.se && a[mr].se > a[i].se))
            mr = i;
        if(a[i].fi.fi < a[ml].fi.fi || (a[i].fi.fi == a[ml].fi.fi && a[ml].se > a[i].se))
            ml = i;
        if(a[i].fi.se - a[i].fi.fi > a[ls].fi.se - a[ls].fi.fi || (a[i].fi.se - a[i].fi.fi == a[ls].fi.se - a[ls].fi.fi && a[ls].se > a[i].se))
            ls = i;
        if(a[ls].fi.se - a[ls].fi.fi == a[mr].fi.se - a[ml].fi.fi)
            cout << min(a[ls].se, a[ml].se + a[mr].se) << endl;
        else
            cout << a[ml].se + a[mr].se << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}