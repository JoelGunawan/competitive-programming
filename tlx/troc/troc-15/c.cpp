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
    ll a, b;
    cin >> a >> b;
    if(b % a)
        cout << -1 << " " << -1 << endl, exit(0);
    ll n = b / a;
    // find factors of n with minimum sum
    // it will always be the closest to sqrt(n)?
    ll x, y, min_res = LLONG_MAX;
    for(ll i = 1; i <= sqrt(n); ++i) {
        if(n % i == 0 && gcd(i, n / i) == 1) {
            if(i + n / i < min_res) 
                x = i, y = n / i, min_res = i + n / i;
        }
    }
    cout << a * x << " " << a * y << endl;
    return 0;
}