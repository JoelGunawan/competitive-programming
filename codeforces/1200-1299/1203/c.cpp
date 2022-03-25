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
    ll a[n], x = 0;
    for(int i = 0; i < n; ++i) 
        cin >> a[i], x = gcd(x, a[i]);
    // find amount of divisors in x
    ll res = 1;
    for(ll i = 2; i * i <= x; ++i) {
        if(x % i == 0) {
            int cnt = 0;
            while(x % i == 0)
                x /= i, ++cnt;
            res *= (cnt + 1);
        }
    }
    if(x > 1)
        res *= 2;
    cout << res << endl;
    return 0;
}