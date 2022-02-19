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
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while(n--) {
        ll p, q, b;
        cin >> p >> q >> b;
        if(p % q == 0) {
            cout << "Finite" << endl;
            continue;
        }
        // inifnite requires there be a number such that q has a prime factor that is not in b
        q /= gcd(p, q);
        while(gcd(b, q) > 1) {
            ll tmp = gcd(b, q);
            b = tmp;
            q /= tmp;
        }
        if(q == 1)
            cout << "Finite" << endl;
        else
            cout << "Infinite" << endl;
    }
    return 0;
}