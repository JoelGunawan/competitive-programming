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
void sub(pair<ll, ll> &a, pair<ll, ll> &b) {
    a.fi -= b.fi;
    a.se -= b.se;
}
void add(pair<ll, ll> &a, pair<ll, ll> &b) {
    a.fi += b.fi;
    a.se += b.se;
}
ll cross(pair<ll, ll> a, pair<ll, ll> b) {
    return a.fi * b.se - a.se * b.fi;
}
bool intersect(pair<pair<ll, ll>, pair<ll, ll>> a, pair<pair<ll, ll>, pair<ll, ll>> b) {
    vector<ll> x(4);
    sub(a.se, a.fi), sub(b.fi, a.fi), sub(b.se, a.fi);
    x[0] = cross(a.se, b.fi), x[1] = cross(a.se, b.se);
    add(a.se, a.fi), add(b.fi, a.fi), add(b.se, a.fi);

    sub(a.fi, b.fi), sub(a.se, b.fi), sub(b.se, b.fi);
    x[2] = cross(b.se, a.fi), x[3] = cross(b.se, a.se);
    add(a.fi, b.fi), add(a.se, b.fi), add(b.se, b.fi);

    if(x[0] == 0 && x[1] == 0 && x[2] == 0 && x[3] == 0) {
        if((a.fi >= min(b.fi, b.se) && a.fi <= max(b.fi, b.se)) || (a.se >= min(b.fi, b.se) && a.se <= max(b.fi, b.se))
        || (b.fi >= min(a.fi, a.se) && b.fi <= max(a.fi, a.se)) || (b.se >= min(b.fi, b.se) && b.se <= max(a.fi, a.se)))
            return 1;
        else
            return 0;
    }
    else if(a.fi == b.fi || a.fi == b.se || a.se == b.fi || a.se == b.se)
        return 1;
    else {
        bool y = 1, z = 1;
        if((x[0] > 0 && x[1] > 0) || (x[0] < 0 && x[1] < 0))
            y = 0;
        if((x[2] > 0 && x[3] > 0) || (x[2] < 0 && x[3] < 0))
            z = 0;
        return y && z;
    }
}
bool func(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    sub(b, a);
    sub(c, a);
    ll x = cross(b, c);
    add(b, a);
    add(c, a);
    if(x == 0 && c >= min(a, b) && c <= max(a, b))
        return 1;
    else
        return 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    // n kali m
    // cari apa garis motong atau ga
    pair<ll, ll> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi >> a[i].se;
    for(int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        pair<ll, ll> cur = mp(x, y);
        pair<ll, ll> inf = mp(x + 2e9 + 1, y + 2e9 + 2);
        int cnt = 0;
        bool boundary = 0;
        for(int j = 0; j < n; ++j) {
            if(intersect(mp(cur, inf), mp(a[j], a[(j + 1) % n])))
                ++cnt;
            if(func(a[j], a[(j + 1) % n], cur))
                boundary = 1;
        }
        //cout << cnt << endl;
        if(boundary)
            cout << "BOUNDARY" << endl;
        else if(cnt & 1)
            cout << "INSIDE" << endl;
        else
            cout << "OUTSIDE" << endl;
    }
    return 0;
}