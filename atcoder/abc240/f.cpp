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
ll sum(ll a) {
    return a * (a + 1) / 2;
}
void tc() {
    int n, m;
    cin >> n >> m;
    pair<ll, ll> arr[n];
    for(int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        arr[i] = mp(x, y);
    }
    ll aprev = 0, bprev = 0, res = -6 * 1e18;
    for(int i = 0; i < n; ++i) {
        ll s = arr[i].se, val = arr[i].fi;
        if(val < 0 && bprev + s * val < 0) {
            // find last instance where b[i] is positive
            // use binary search
            ll l = 1, r = s, x = 1;
            while(l <= r) {
                ll mid = (l + r) / 2;
                if(bprev + val * mid < 0)
                    r = mid - 1;
                else
                    l = mid + 1, x = mid;
            }
            //cout << i << " " << x << endl;
            res = max(res, aprev + bprev * x + val * sum(x));
        }
        aprev = aprev + bprev * s + val * sum(s);
        bprev = bprev + s * val;
        res = max(res, aprev);
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}