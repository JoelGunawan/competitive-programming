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
void tc() {
    vector<pair<ll, ll>> a(3);
    for(int i = 0; i < 3; ++i) {
        ll x, y;
        cin >> x >> y;
        a[i] = mp(x, y);
    }
    for(int i = 1; i < 3; ++i) {
        a[i].fi -= a[0].fi;
        a[i].se -= a[0].se;
    }
    ll cross_product = a[1].fi * a[2].se - a[2].fi * a[1].se;
    //cout << cross_product << " ";
    if(cross_product > 0)
        cout << "LEFT" << endl;
    else if(cross_product < 0)
        cout << "RIGHT" << endl;
    else
        cout << "TOUCH" << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}