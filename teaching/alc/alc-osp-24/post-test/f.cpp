#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int mod = 1e9 + 7;
ll fact[100005], inv[100005];
ll powmod(ll a, ll b) {
    if(b == 0) {
        return 1;
    }
    else {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        if(b % 2 == 1) {
            return (tmp * a) % mod;
        }
        else {
            return tmp;
        }
    }
}
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
ll combinmod(ll a, ll b) {
    return mul(fact[a], mul(inv[a - b], inv[b]));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= 100000; ++i) {
        fact[i] = mul(fact[i - 1], i), inv[i] = powmod(fact[i], mod - 2);
    }
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        int n, x, y;
        cin >> n >> x >> y;
        ll hasil = 0;
        ll pangkatx[n + 1], pangkaty[n + 1];
        pangkatx[0] = pangkaty[0] = 1;
        for(int i = 1; i <= n; ++i) {
            pangkatx[i] = (pangkatx[i - 1] * x) % mod;
            pangkaty[i] = (pangkaty[i - 1] * y) % mod;
        }
        for(int j = 0; j <= n; ++j) {
            hasil += mul(pangkatx[j], mul(pangkaty[n - j], combinmod(n, j))); 
        }
        cout << hasil % mod << endl;
    }
}