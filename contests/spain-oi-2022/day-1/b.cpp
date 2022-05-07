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
const ll lim = 1e18;
ll query(ll l, ll r) {
    cout << "? " << l << " " << r << endl;
    ll n;
    cin >> n;
    if(n == 0)
        exit(0);
    return n;
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll mod = 1;
    ll a = 0, b = 0;
    mod = query(a, b);
    while(mod <= lim) {
        // coba beberapa konfigurasi 
        // try different configurations
        // try add a
        while(a + mod >= lim)
            a -= mod;
        while(b + mod >= lim)
            b -= mod;
        ll tmp2 = a + mod, tmp3 = query(tmp2, b);
        if(tmp3 == mod) {
            ll tmp4 = b + mod, tmp5 = query(tmp2, tmp4);
            if(tmp5 == mod) {
                b += mod;
                mod = query(a, b);
            }
            else {
                a = tmp2, b = tmp4;
                mod = tmp5;
            }
        }
        else {
            a = tmp2;
            mod = tmp3;
        }
    }
    while(a <= 0)
        a += mod;
    while(b <= 0)
        b += mod;
    while(a > 1e18)
        a -= mod;
    while(b > 1e18)
        b -= mod;
    query(a, b);
    return 0;
}