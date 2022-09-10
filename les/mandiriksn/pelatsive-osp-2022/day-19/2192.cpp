#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define mp make_pair
using namespace std;
ll cross_product(pair<ll, ll> a, pair<ll, ll> b) {
    return a.x * b.y - a.y * b.x;
}
pair<ll, ll> sub(pair<ll, ll> a, pair<ll, ll> b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
}
bool intersect(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<int, int> d) {
    // a itu utama
    ll dres = cross_product(sub(b, a), sub(d, a)), cres = cross_product(sub(b, a), sub(c, a));
    if(dres < 0)
        dres = -1;
    if(dres > 0)
        dres = 1;
    if(cres < 0)
        cres = -1;
    if(cres > 0)
        cres = 1;
    ll ares = cross_product(sub(d, c), sub(a, c)), bres = cross_product(sub(d, c), sub(b, c));
    if(ares < 0)
        ares = -1;
    if(ares > 0)
        ares = 1;
    if(bres < 0)
        bres = -1;
    if(bres > 0)
        bres = 1;
    return ares == -bres && cres == -dres;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    pair<ll, ll> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y;
    for(int i = 0; i < m; ++i) {
        pair<ll, ll> cur;
        cin >> cur.x >> cur.y;
        pair<ll, ll> inf = {cur.x + 2e9 + 2, cur.y + 2e9 + 3};
        int cnt = 0;
        bool boundary = 0;
        for(int j = 0; j < n; ++j) {
            if(cross_product(sub(a[(j + 1) % n], a[j]), sub(cur, a[j])) == 0 
            && cur >= min(a[j], a[(j + 1) % n]) && cur <= max(a[j], a[(j + 1) % n]))
                boundary = 1;
            if(a[j] != a[(j + 1) % n] && intersect(cur, inf, a[j], a[(j + 1) % n]))
                ++cnt;
        }
        if(boundary)
            cout << "BOUNDARY" << endl;
        else if(cnt & 1)
            cout << "INSIDE" << endl;
        else
            cout << "OUTSIDE" << endl;
    }
}