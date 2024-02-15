#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7;
const int lim = 1e5 + 5;
ll fact[lim], inv[lim];
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
ll add(ll a, ll b) {
    return (a + b) % mod;
}
ll sub(ll a, ll b) {
    return (((a - b) % mod) + mod) % mod;
}
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        // ganjil -> 2^(x/2)*2^(x/2)*2 
        // genap -> 2^(x/2)*2^(x/2)
        ll ret = powmod(a, b >> 1);
        ret = mul(ret, ret);
        return b & 1 ? mul(ret, a) : ret;
    }
}
ll combinmod(ll a, ll b) {
    return mul(fact[a], mul(inv[b], inv[a - b]));
}
int main() {
    fact[0] = inv[0] = 1;
    for(int i = 1; i < lim; ++i)
        fact[i] = (fact[i - 1] * i) % mod, inv[i] = powmod(fact[i], mod - 2);
    cout << combinmod(5, 3);
}