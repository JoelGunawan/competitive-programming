// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
ll r, c, q;
bool valid(ll x, ll y) {
    return x >= 1 && x <= r && y >= 1 && y <= c;
}
ll query(ll x, ll y) {
    assert(valid(x, y));
    cout << "? " << x << " " << y << endl;
    ll n;
    cin >> n;
    return n;
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c >> q;
    ll A = query(1, 1), B = query(r, 1), C = query(1, c), D = query(r, c);
    /*
        A = x - 1 + y - 1
        B = r - x + y - 1
        A + B = 2y + r - 3
        2y = A + B - r + 3
        y = (A + B - r + 3) / 2
        A = x - 1 + y - 1
        A = x + y - 2
        x = A - y + 2 

        C = x - 1 + c - y
        D = r - x + c - y
        C + D = r - 1 + 2c - 2y
        2y = r - 1 + 2c - C - D
        y = (r - 1 + 2c - C - D) / 2
        C = x - 1 + c - y
        C = x + c - y - 1
        x = C + y + 1 - c

    */
    pair<ll, ll> x1 = {(A - (A + B - r + 3) / 2 + 2), (A + B - r + 3) / 2},
    x2 = {C - c + (r - 1 + 2 * c - C - D) / 2 + 1, (r - 1 + 2 * c - C - D) / 2}, 
    y1 = {(A + C - c + 3) / 2, (A - (A + C - c + 3) / 2 + 2)}, 
    y2 = {(c - 1 + 2 * r - B - D) / 2, B - r + (c - 1 + 2 * r - B - D) / 2 + 1};
    //cout << "! " << x1.fi << " " << x1.se << " " << x2.fi << " " << x2.se << endl;
    //cout << "! " << y1.fi << " " << y1.se << " " << y2.fi << " " << y2.se << endl;
    if((A + B - r + 3) < 0 || (r - 1 + 2 * c - C - D) < 0 || (A + B - r + 3) & 1 || (r - 1 + 2 * c - C - D) & 1) {
        // output y1 and y2
        cout << "! " << y1.fi << " " << y1.se << " " << y2.fi << " " << y2.se << endl;
    }
    else {
        if(x1 == y1 || x1 == y2) {
            // compare from x2
            if(valid(x1.fi, x1.se) && valid(x2.fi, x2.se) && query(x2.fi, x2.se) == 0)
                cout << "! " << x1.fi << " " << x1.se << " " << x2.fi << " " << x2.se << endl;
            else
                cout << "! " << y1.fi << " " << y1.se << " " << y2.fi << " " << y2.se << endl;
        }
        else if(valid(x2.fi, x2.se) && valid(x1.fi, x1.se) && query(x1.fi, x1.se) == 0)
            cout << "! " << x1.fi << " " << x1.se << " " << x2.fi << " " << x2.se << endl;
        else
            cout << "! " << y1.fi << " " << y1.se << " " << y2.fi << " " << y2.se << endl;
    }
    return 0;
}   