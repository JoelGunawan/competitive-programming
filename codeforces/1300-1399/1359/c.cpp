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
    ll h, c, t;
    cin >> h >> c >> t;
    if(h == t) {
        cout << 1 << endl;
        return;
    }
    if(h + c == 2 * t) {
        cout << 2 << endl;
        return;
    }
    // hx+cy=t*(x + y)
    // has to be alternating
    // binary/ternary search for alternating moves
    // do 4 binser
    // approach from smaller
    // approach from larger
    // do for even and odd
    // odd smaller binser
    ll l = 1, r = 1e6;
    pair<double, int> ans[4];
    for(int i = 0; i < 4; ++i)
        ans[i] = mp(1e20, 100000);
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(mid * h + (mid - 1) * c <= (mid + (mid - 1)) * t)
            l = mid + 1, ans[0] = min(ans[0], mp(abs(mid * h + (mid - 1) * c - (mid + (mid - 1)) * t) / (double)(2 * mid - 1), 2 * (int)mid - 1));
        else
            r = mid - 1;
    }
    l = 1, r = 1e6;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(mid * h + (mid - 1) * c >= (mid + (mid - 1)) * t)
            l = mid + 1, ans[0] = min(ans[0], mp(abs(mid * h + (mid - 1) * c - (mid + (mid - 1)) * t) / (double)(2 * mid - 1), 2 * (int)mid - 1));
        else
            r = mid - 1;
    }
    l = 1, r = 1e6;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(mid * h + (mid - 1) * c <= (mid + (mid - 1)) * t)
            r = mid - 1, ans[1] = min(ans[1], mp(abs(mid * h + (mid - 1) * c - (mid + (mid - 1)) * t) / (double)(2 * mid - 1), 2 * (int)mid - 1));
        else
            l = mid + 1;
    }
    l = 1, r = 1e6;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(mid * h + (mid - 1) * c >= (mid + (mid - 1)) * t)
            r = mid - 1, ans[1] = min(ans[1], mp(abs(mid * h + (mid - 1) * c - (mid + (mid - 1)) * t) / (double)(2 * mid - 1), 2 * (int)mid - 1));
        else
            l = mid + 1;
    }
    l = 1, r = 1e6;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(mid * h + mid * c <= (2 * mid * t))
            l = mid + 1, ans[2] = min(ans[2], mp(abs(mid * h + mid * c - 2 * mid * t) / (double)(2 * mid), 2 * (int)mid));
        else
            r = mid - 1;
    }
    l = 1, r = 1e6;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(mid * h + mid * c >= (2 * mid * t))
            l = mid + 1, ans[2] = min(ans[2], mp(abs(mid * h + mid * c - 2 * mid * t) / (double)(2 * mid), 2 * (int)mid));
        else
            r = mid - 1;
    }
    l = 1, r = 1e6;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(mid * h + mid * c <= (2 * mid * t))
            r = mid - 1, ans[3] = min(ans[3], mp(abs(mid * h + mid * c - 2 * mid * t) / (double)(2 * mid), 2 * (int)mid));
        else
            l = mid + 1;
    }
    l = 1, r = 1e6;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(mid * h + mid * c >= (2 * mid * t))
            r = mid - 1, ans[3] = min(ans[3], mp(abs(mid * h + mid * c - 2 * mid * t) / (double)(2 * mid), 2 * (int)mid));
        else
            l = mid + 1;
    }
    sort(ans, ans + 4);
    cout << ans[0].se << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}