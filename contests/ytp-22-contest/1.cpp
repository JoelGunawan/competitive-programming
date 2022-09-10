#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 3000000019;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main() {
    int n;
    string s;
    cin >> s;
    n = (s.size() >> 1) + 1;
    int a[n];
    int sum = 0;
    for(int i = 0; i <= s.size() >> 1; ++i) {
        a[i] = s[2 * i] - '0';
        sum += a[i];
    }
    ll fact[sum + 1];
    fact[0] = 1;
    for(int i = 1; i <= sum; ++i)
        fact[i] = (fact[i - 1] * i) % mod;
    ll res = fact[sum];
    for(int i = 0; i < n; ++i) {
        res *= powmod(fact[a[i]], mod - 2), res %= mod;
    }
    cout << res << endl;
}