#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7;
// O(logb)
ll powmod(ll a, ll b) {
    if(b == 0) {
        return 1;
    }
    else {
        ll tmp = powmod(a, b / 2); // a^(b/2)
        tmp = (tmp * tmp) % mod;
        if(b % 2 == 0) {
            // b genap
            // a^(b/2) * a^(b/2) = a^b
            return tmp;
        }
        else {
            // b ganjil
            // a*a^(b/2)*a^(b/2)=a^(b-1)*a
            return (tmp * a) % mod;
        }
    }
}
ll fact[2000005], inv[2000005];
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
ll combinmod(ll a, ll b) {
    return mul(fact[a], mul(powmod(fact[a - b], mod - 2), powmod(fact[b], mod - 2)));
}
int main() {
    fact[0] = 1;
    for(int i = 1; i <= 2000000; ++i) {
        // faktorial -> O(N)
        // setiap inverse -> O(log(mod))
        fact[i] = (fact[i - 1] * i) % mod;
    }
    int n, m;
    cin >> n >> m;
    cout << combinmod(n + m - 1, m) << endl;
}