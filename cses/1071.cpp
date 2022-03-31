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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll x, y;
        cin >> x >> y;
        bool odd = max(x, y) & 1;
        if(x == y) {
            cout << ((x * x + (x - 1) * (x - 1)) >> 1) + 1 << endl;
        }
        else if(odd) {
            if(x < y) {
                cout << y * y - (x - 1) << endl;
            }
            else
                cout << (x - 1) * (x - 1) + y << endl;
        }
        else {
            if(x < y) {
                cout << (y - 1) * (y - 1) + x << endl;
            }
            else {
                cout << x * x - (y - 1) << endl;
            }
        }
    }
    return 0;
}