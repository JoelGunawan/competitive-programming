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
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
void tc() {
    int x, y;
    cin >> x >> y;
    int xmsb = -1, ymsb = -1;
    for(int i = 0; i <= 30; ++i) {
        if((1 << i) & x)
            xmsb = i;
        if((1 << i) & y)
            ymsb = i;
    }
    if(x == 0 || y == 0)
        cout << max(x, y) << endl;
    else {
        ll res = 0;
        for(int i = 0; i <= max(xmsb, ymsb); ++i) {
            // pick how many has 3 states
            // pick how many has 2 states
            if(i > xmsb || i > ymsb) {
                res += ((i + 1) * powmod(2, i - min(xmsb, ymsb) - 1) * powmod(3, min(xmsb, ymsb)));
                res %= mod;
            }
            else
                res += ((i + 1) * 2 * powmod(3, i)) % mod;
                res %= mod;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}