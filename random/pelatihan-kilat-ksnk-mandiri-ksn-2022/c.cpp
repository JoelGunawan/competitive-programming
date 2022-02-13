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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // permutasi ukuran 2n
    // permutasi panjangnya genap
    // 1, 2, 3, ... 2n
    // count(p[i] < p[i + 1]) >= n
    // 1 | 2 | 3 | 4
    // 1 1 1
    // 4 | 3 | 2 | 1
    // 0 0 0
    // 3 | 2 | 1 | 4
    // 0 0 1
    // 4 | 1 | 2 | 3
    // 1 1 0
    // kita perlu cari setengah dari banyaknya jumlah permutasi yang ukurannya 2n
    // (2n)!/2
    ll fact[200001];
    fact[0] = 1;
    for(int i = 1; i <= 200000; ++i)
        fact[i] = (fact[i - 1] * i) % mod;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << (fact[2 * n] * powmod(2, mod - 2)) % mod << endl;
    }
    return 0;
}