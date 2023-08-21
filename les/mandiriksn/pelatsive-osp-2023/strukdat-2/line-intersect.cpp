#include <bits/stdc++.h>
#define ll long long
#define fi first 
#define se second
using namespace std;
ll cross(pair<ll, ll> a, pair<ll, ll> b) {
    return a.first * b.second - b.first * a.second;
}
pair<ll, ll> sub(pair<ll, ll> a, pair<ll, ll> b) {
    return {a.fi - b.fi, a.se - b.se};
}
bool intersect(pair<pair<ll, ll>, pair<ll, ll>> a, pair<pair<ll, ll>, pair<ll, ll>> b) {
    // cari posisi tiap b relatif ke tiap a
    // consider kasus lurus dlu
    ll ac = cross(sub(a.se, a.fi), sub(b.fi, a.fi)), ad = cross(sub(a.se, a.fi), sub(b.se, a.fi))
    , bc = cross(sub(a.fi, a.se), sub(b.fi, a.se)), bd = cross(sub(a.fi, a.se), sub(b.se, a.se));
    //cout << ac << " " << ad << " " << bc << " " << bd << endl;
    if(ac == 0 && ad == 0 && bc == 0 && bd == 0) {
        // kasus khusus
        if((a.fi >= min(b.fi, b.se) && a.fi <= max(b.fi, b.se)) || (a.se >= min(b.fi, b.se) && a.se <= max(b.fi, b.se))
        || (b.fi >= min(a.fi, a.se) && b.fi <= max(a.fi, a.se)) || (b.se >= min(a.fi, a.se) && b.se <= max(a.fi, a.se)))
            return 1;
        else
            return 0;
    }
    ll ca = cross(sub(b.se, b.fi), sub(a.fi, b.fi)), cb = cross(sub(b.se, b.fi), sub(a.se, b.fi))
    , da = cross(sub(b.fi, b.se), sub(a.fi, b.se)), db = cross(sub(b.fi, b.se), sub(a.se, b.se));
    bool ans1 = 0, ans2 = 0;
    if(ac <= 0 && ad >= 0 && bc >= 0 && bd <= 0) {
        ans1 = 1;
    }
    if(ac >= 0 && ad <= 0 && bc <= 0 && bd >= 0) {
        ans1 = 1;
    }
    if(ca <= 0 && cb >= 0 && da >= 0 && db <= 0) {
        ans2 = 1;
    }
    if(ca >= 0 && cb <= 0 && da <= 0 && db >= 0) {
        ans2 = 1;
    }
    return ans1 && ans2;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        pair<ll, ll> a, b, c, d;
        cin >> a.fi >> a.se >> b.fi >> b.se >> c.fi >> c.se >> d.fi >> d.se;
        // ab cd
        if(intersect({a, b}, {c, d})) {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}