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
ll cross_product(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    b.fi -= a.fi;
    c.fi -= a.fi;
    b.se -= a.se;
    c.se -= a.se;
    return b.fi * c.se - c.fi * b.se;
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
    vector<pair<ll, ll>> s;
    s.pb(a[0]);
    s.pb(a[1]);
    for(int i = 2; i < n; ++i) {
        // consider everything in a
        while(s.size() > 1 && cross_product(s[s.size() - 2], s[s.size() - 1], a[i]) < 0)
            s.pop_back();
        s.pb(a[i]);
    }
    set<pair<ll, ll>> ans;
    for(auto i : s)
        ans.ins(i);
    s.clear();
    s.pb(a[n - 1]);
    s.pb(a[n - 2]);
    for(int i = n - 3; i >= 0; --i) {
        while(s.size() > 1 && cross_product(s[s.size() - 2], s[s.size() - 1], a[i]) < 0)
            s.pop_back();
        s.pb(a[i]);
    }
    for(auto i : s)
        ans.ins(i);
    cout << ans.size() << endl;
    for(auto i : ans)
        cout << i.fi << " " << i.se << endl;
    return 0;
}