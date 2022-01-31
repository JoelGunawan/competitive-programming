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
ll INF = 1e18;
ll sqr(ll a) {
    return a * a;
}
ll get_dist(pair<ll, ll> a, pair<ll, ll> b) {
    return sqr(a.fi - b.fi) + sqr(a.se - b.se);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    pair<ll, ll> a[n];
    for(int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        a[i] = mp(x, y);
    }
    sort(a, a + n);
    // fi is x
    set<pair<ll, ll>> s;
    // fi is y
    set<pair<ll, ll>> t;
    ll min_dist = 9 * (ll)1e18;
    for(int i = 0; i < n; ++i) {
        while(s.size() > 0 && (*s.begin()).fi < a[i].fi - sqrt(min_dist)) {
            t.erase(t.find(mp((*s.begin()).se, (*s.begin()).fi)));
            s.erase(s.begin());
        }
        pair<ll, ll> tmp;
        auto it = t.lb(mp(a[i].se - sqrt(min_dist), -INF));
        while(it != t.end() && (*it).fi <= a[i].se + sqrt(min_dist)) {
            min_dist = min(min_dist, get_dist(mp(a[i].se, a[i].fi), *it));
            ++it;
        }
        s.ins(a[i]);
        t.ins(mp(a[i].se, a[i].fi));
    }
    cout << min_dist << endl;
    return 0;
}