// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define ld long double
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
struct line {
    ll m = 0, c = 0;
};

ll eval(line a, ll x) {
    return a.m * x + a.c;
}

ld intersect(line a, line b) {
    return (a.c - b.c) / (ld)(b.m - a.m);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    pair<pair<ll, ll>, ll> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
    sort(a, a + n);
    deque<line> cht;
    cht.pb(line());
    ll dp[n];
    for(int i = 0; i < n; ++i) {
        // create a cht formula
        // where we find intersect points between lines
        // decreasing j.x, decreasing i.y
        // decreasing -> kita insert di paling kiri, kita cari rightmost point, jadi while intersectnya cur sm back itu lebih besar dari 
        //cout << a[i].fi.fi << " " << a[i].fi.se << endl;
        while(cht.size() >= 2 && intersect(cht[0], cht[1]) >= a[i].fi.se)
            cht.pop_front();
        //cout << cht[ans].m << " " << cht[ans].c << " " << a[i].fi.fi << " " << a[i].fi.se << " " << dp[i] << endl;
        //cout << dp[i] << " ";
        //cout << endl;
        dp[i] = eval(cht.front(), a[i].fi.se) + a[i].fi.fi * a[i].fi.se - a[i].se;
        line cur;
        cur.m = -a[i].fi.fi;
        cur.c = dp[i];
        while(cht.size() >= 2 && intersect(cht.back(), cur) >= intersect(cht.back(), cht[cht.size() - 2])) {
            cht.pop_back();
        }
        cht.pb(cur);
    }
    ll res = 0;
    for(int i = 0; i < n; ++i)
        res = max(res, dp[i]);
    cout << res << endl;
    return 0;
}