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
ll f(pair<ll, ll> a, pair<ll, ll> b) {
    return a.fi * b.se - a.se * b.fi;
}
void tc() {
    pair<ll, ll> arr[4];
    for(int i = 0; i < 4; ++i) {
        ll x, y;
        cin >> x >> y;
        arr[i] = mp(x, y);
    }
    ll a, b, c, d;
    for(int i = 1; i < 4; ++i) {
        arr[i].fi -= arr[0].fi;
        arr[i].se -= arr[0].se;
    }
    a = f(arr[1], arr[2]), b = f(arr[1], arr[3]);
    for(int i = 1; i < 4; ++i) {
        arr[i].fi += arr[0].fi;
        arr[i].se += arr[0].se;
    }
    for(int i = 0; i < 4; ++i) {
        if(i != 2) {
            arr[i].fi -= arr[2].fi;
            arr[i].se -= arr[2].se;
        }
    }
    c = f(arr[3], arr[0]), d = f(arr[3], arr[1]);
    for(int i = 0; i < 4; ++i) {
        if(i != 2) {
            arr[i].fi += arr[2].fi;
            arr[i].se += arr[2].se;
        }
    }
    // case of same line
    // find cross products
    //cout << a << " " << b << " " << c << " " << d << endl;
    if(a == 0 && b == 0 && c == 0 && d == 0 && 
    ((arr[0] >= min(arr[2], arr[3]) && arr[0] <= max(arr[2], arr[3])) || (arr[1] >= min(arr[2], arr[3]) && arr[1] <= max(arr[2], arr[3])) 
    || (arr[2] >= min(arr[0], arr[1]) && arr[2] <= max(arr[0], arr[1])) || (arr[3] >= min(arr[0], arr[1]) && arr[3] <= max(arr[0], arr[1])))) {
        //cout << "TEST1" << endl;
        cout << "YES" << endl;
        return;
    }
    else if(a == 0 && b == 0 && c == 0 && d == 0) {
        cout << "NO" << endl;
        return;
    }
    // case of one point is the same
    if(arr[0] == arr[2] || arr[0] == arr[3] || arr[1] == arr[2] || arr[1] == arr[3]) {
        //cout << "TEST2" << endl;
        cout << "YES" << endl;
        return;
    }
    // case if only one point intersects
    bool x = 1, y = 1;
    if((a > 0 && b > 0) || (a < 0 && b < 0))
        x = 0;
    if((c > 0 && d > 0) || (c < 0 && d < 0))
        y = 0;
    if(x && y)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}