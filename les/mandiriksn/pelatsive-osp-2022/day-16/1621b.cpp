#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
void tc() {
    // maintain 3 variable
    // pertama -> harga
    // kedua -> index
    int left, right, left_right;
    int n;
    cin >> n;
    pair<pair<int, int>, int> a[n];
    for(int i = 0; i < n; ++i) {
        int l, r, c;
        cin >> l >> r >> c;
        a[i] = {make_pair(l, r), c};
    }
    cout << a[0].se << endl;
    // a[i].fi.fi -> awal segment (L_i)
    // a[i].fi.se -> akhir segment (R_i)
    // a[i].se -> harga segment (C_i)
    left = 0, right = 0, left_right = 0;
    for(int i = 1; i < n; ++i) {
        if(a[i].fi.fi < a[left].fi.fi || (a[i].fi.fi == a[left].fi.fi && a[i].se < a[left].se))
            left = i;
        if(a[i].fi.se > a[right].fi.se || (a[i].fi.se == a[right].fi.se && a[i].se < a[right].se))
            right = i;
        if(a[i].fi.fi == a[left].fi.fi && a[i].fi.se == a[right].fi.se 
        && ((a[left_right].fi.fi != a[left].fi.fi || a[left_right].fi.se != a[right].fi.se) || (a[i].se < a[left_right].se)))
            left_right = i;
        if(a[left_right].fi.fi == a[left].fi.fi && a[left_right].fi.se == a[right].fi.se)
            cout << min(a[left_right].se, a[left].se + a[right].se) << endl;
        else
            cout << a[left].se + a[right].se << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--)
        tc();
}