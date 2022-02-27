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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    ll total = 0;
    sort(a, a + n);
    for(auto i : a) 
        total += i;
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        // find first that is lower
        // find first that is larger
        // it is always between those two that are optimal
        ll lower = 0, higher = 0;
        auto it = upper_bound(a, a + n, x);
        if(upper_bound(a, a + n, x) != a)
            lower = *--it;
        if(upper_bound(a, a + n, x) != a + n)
            higher = *upper_bound(a, a + n, x);
        ll res = LLONG_MAX;
        if(lower) {
            res = min(res, x - lower + max(0ll, -(total - lower - y)));
        }
        if(higher) {
            res = min(res, max(0ll, y - (total - higher)));
        }
        cout << res << endl;
    }
    return 0;
}