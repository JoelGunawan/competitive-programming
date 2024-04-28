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
ll query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    ll ret;
    cin >> ret;
    return ret;
}
void answer(ll x, ll y) {
    cout << "! " << x << " " << y << endl;
    exit(0);
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll x, y, q;
    cin >> x >> y >> q;
    ll a, b, c = 1ll * (y - 1) * (y - 1);
    if(x == 1) {
        a = query(1, 1);
        answer(1, 1 + round(sqrt((long double)a)));
    }
    else if(y == 1) {
        a = query(1, 1);
        answer(1 + round(sqrt((long double)a)), 1);
    }
    a = query(1, 1), b = query(1, y);
    if(a == 0) {
        answer(1, 1);
    }
    else if(b == 0) {
        answer(1, y);
    }
    ll ycoords = round((a + c - b) / (2 * (long double)sqrt(c))) + 1;
    ll xcoords = round((double)sqrt(a - 1ll * (ycoords - 1) * (ycoords - 1))) + 1;
    answer(xcoords, ycoords);
    return 0;
}