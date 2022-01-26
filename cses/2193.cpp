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
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll cross(pair<ll, ll> a, pair<ll, ll> b) {
    return a.fi * b.se - a.se * b.fi;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // area = a + b / 2 - 1
    // a -> inside boundary
    // b -> on boundary
    // calculate how many integer points are on the boundary
    // basically by finding gcd
    // ex 4 2
    // it means 2 int points on boundary
    int n;
    cin >> n;
    pair<ll, ll> a[n];
    for(int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        a[i] = mp(x, y);
    }
    ll area = 0, on_boundary = 0;
    for(int i = 0; i < n; ++i) {
        area += cross(a[i], a[(i + 1) % n]);
    }
    for(int i = 0; i < n; ++i) {
        on_boundary += gcd(abs(a[i].fi - a[(i + 1) % n].fi), abs(a[i].se - a[(i + 1) % n].se));
    }
    area = abs(area);
    cout << (area - on_boundary) / 2 + 1 << " " << on_boundary << endl;
    return 0;
}