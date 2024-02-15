#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#include <bits/stdc++.h>
using namespace std;
pair<ll, ll> sub(pair<ll, ll> a, pair<ll, ll> b) {
    a.fi -= b.fi;
    a.se -= b.se;
    return a;
}
ll cross_product(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    b = sub(b, a);
    c = sub(c, a);
    return 1ll * b.fi * c.se - 1ll * b.se * c.fi;
}
bool between(ll a, ll l, ll r) {
    if(l >= r)
        swap(l, r);
    return a >= l && a <= r;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    pair<ll, ll> a[n];
    for(ll i = 0; i < n; ++i)
        cin >> a[i].fi >> a[i].se;
    pair<ll, ll> c, s;
    cin >> c.fi >> c.se >> s.fi >> s.se;
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += cross_product({0, 0}, a[i], a[(i + 1) % n]);
    }
    if(sum < 0)
        reverse(a, a + n);
    for(ll i = 0; i < n; ++i) {
        if(c == a[i]) {
            ll pr = (i - 1 + n) % n, nxt = (i + 1) % n;
            string ans1 = "a", ans2 = "b";
            if(cross_product(a[pr], a[i], s) > 0) {
                ans1 = "inside";
            }   
            else if(cross_product(a[pr], a[i], s) == 0) {
                ans1 = "?";
            }   
            else {
                ans1 = "outside";
            }    
            if(cross_product(a[i], a[nxt], s) > 0) {
                ans2 = "inside";
            }   
            else if(cross_product(a[i], a[nxt], s) == 0) {
                ans2 =  "?";
            }   
            else {
                ans2 = "outside";
            }    
            assert(ans1 != "a" && ans2 != "b");
            if(ans1 == ans2) {
                cout << ans1 << endl;
            }
            else {
                cout << "?" << endl;
            }
            return 0;
        }
    }
    for(ll i = 0; i < n; ++i) {
        // check in this segment
        if(cross_product(a[i], c, a[(i + 1) % n]) == 0 && 
            ((a[i] <= c && c <= a[(i + 1) % n])
            || (a[(i + 1) % n] <= c && c <= a[i]))) {
            if(cross_product(a[i], a[(i + 1) % n], s) > 0) {
                cout << "inside" << endl;
            }   
            else if(cross_product(a[i], a[(i + 1) % n], s) == 0) {
                cout << "?" << endl;
            }   
            else {
                cout << "outside" << endl;
            }     
            return 0;
        }
    }
    assert(false);
}