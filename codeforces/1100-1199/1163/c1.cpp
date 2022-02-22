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
struct point {
    ll x = 0, y = 0;
    bool operator<(const point &a) const {
        return mp(x, y) < mp(a.x, a.y);
    }
};
struct line {
    ll x = 0, y = 0, c = 0;
    bool operator<(const line &a) const {
        return mp(mp(x, y), c) < mp(mp(a.x, a.y), a.c);
    }
};
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    // we need to find
    // amount of distinct lines
    // and the duplicates are lines with the same gradient
    point a[n];
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i].x = x, a[i].y = y;
    }  
    set<line> s;
    //cout << endl;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            // insert the line into s
            // constant is y if x is 0
            line cur;
            ll deltax = a[i].x - a[j].x, deltay = a[i].y - a[j].y;
            //cout << deltax << " " << deltay << endl;
            cur.y = deltay, cur.x = deltax;
            if(cur.x < 0 || (cur.x == 0 && cur.y < 0))
                cur.x *= -1, cur.y *= -1;
            ll tmp = gcd(abs(cur.x), abs(cur.y));
            cur.x /= tmp, cur.y /= tmp;
            cur.c = (a[i].y * cur.x - a[i].x * cur.y);
            //cout << cur.x << " " << cur.y << " " << cur.c << endl;
            s.ins(cur);
        }
    }
    //for(auto i : s)
    //    cout << i.x << " " << i.y << endl;
    ll res = (ll)s.size() * ((ll)s.size() - 1) / 2;
    map<point, ll> cnt;
    for(auto i : s) {
        point tmp;
        tmp.x = i.x, tmp.y = i.y;
        ++cnt[tmp];
    }
    //cout << "TEST" << endl;
    for(auto i : cnt) 
        res -= max(0ll, 1ll * i.se * (i.se - 1) / 2);
    cout << res << endl;
    return 0;
}