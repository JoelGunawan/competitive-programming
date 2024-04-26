#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int mod = 1e9 + 7;
const int lim = 2e6 + 5;
ll fact[lim];
ll powmod(ll a, ll b) {
    if(b == 0) {
        return 1;
    }
    else {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
ll combin(ll a, ll b) {
    return mul(fact[a], mul(powmod(fact[a - b], mod - 2), powmod(fact[b], mod - 2)));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    // batas n + m -> 2 * 10^6
    fact[0] = 1;
    for(int i = 1; i < lim; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    cout << combin(n + m - 1, n - 1) << endl;
}