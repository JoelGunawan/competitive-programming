#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ins insert
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> x(a), y(b), z(c);
    ll as = 0, bs = 0, cs = 0;
    for(int i = 0; i < a; ++i)
        cin >> x[i], as += x[i];
    for(int i = 0; i < b; ++i)
        cin >> y[i], bs += y[i];
    for(int i = 0; i < c; ++i)
        cin >> z[i], cs += z[i];
    // this is the base
    ll res = max(as + bs - cs, max(as + cs - bs, bs + cs - as));
    // optimize res
    // select minimum dari tiap line
    // terus sum semua dikurangi either 2 of the minimums
    int am = INT_MAX, bm = INT_MAX, cm = INT_MAX;
    for(int i = 0; i < a; ++i)  
        am = min(x[i], am);
    for(int i = 0; i < b; ++i)
        bm = min(y[i], bm);
    for(int i = 0; i < c; ++i)
        cm = min(z[i], cm);
    res = max(res, as + bs + cs - 2 * min(am + bm, min(am + cm, bm + cm)));
    cout << res << endl;
    return 0;
}