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
lll cross_product(pair<lll, lll> a, pair<lll, lll> b) {
    return a.fi * b.se - a.se * b.fi;
}
lll calc(pair<lll, lll> a, pair<lll, lll> b, pair<lll, lll> c) {
    b.fi -= a.fi;
    b.se -= a.se;
    c.fi -= a.fi;
    c.se -= a.se;
    return cross_product(b, c);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    int t;
    cin >> t;
    cin >> n;
    pair<lll, lll> points[n];
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = mp(x, y);
    }
    // for each pair
    // cek apa perkaliannya itu <= 0
    cin >> q;
    while(q--) {
        ll tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        lll a = tmp1, b = tmp2;
        bool ans = 0;
        for(int i = 0; i < n / 2; ++i) {
            // do i to i + 1, i + n / 2 + 1 to i + n / 2
            lll x = calc(points[i], points[(i + 1) % n], mp(a, b)),
            y = calc(points[(i + n / 2 + 1) % n], points[(i + n / 2) % n], mp(a, b));
            if(x >= 0 && y <= 0)
                ans = 1;
        }
        // perlu cek titik pemotongan
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}