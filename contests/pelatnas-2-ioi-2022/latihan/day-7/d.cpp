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
    ios_base::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);
    int n;
    cin >> n;
    ll a[n + 1];
    for(int i = 0; i <= n; ++i)
        cin >> a[i];
    ll subtree[n][2 * n + 1];
    memset(subtree, 0, sizeof(subtree));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= n; ++j) {
            if(j == 0)
                subtree[i][j] = 1;
            else if(i + j - 1 <= n)
                subtree[i][j] = subtree[i][j - 1] * a[i + j - 1];
            else
                break;
            subtree[i][j] %= mod;
        }
    }
    ll div2 = powmod(2, mod - 2);
    for(int i = 1; i <= 2 * n; ++i) {
        ll res = 0;
        for(int j = 0; j < n; ++j) {
            // multiply result by node count at current depth
            ll tmp = ((a[j] - 1) * powmod(a[j], mod - 2)) % mod;
            ll tmp2 = 0;
            for(int k = 0; k <= i / 2; ++k) {
                // kita boleh pilih sembarang asal ga di child yang sama
                // berarti kita kali (a[j] - 1) * a[j]
                // final answer -> 
                // special case, dimana kita harus bagi 2
                if(k == 0) {
                    tmp2 += (subtree[j][k] * subtree[j][i - k]) % mod;
                }
                else if(i - k == k) {
                    tmp2 += (((((((subtree[j][k] * subtree[j][i - k]) % mod) * tmp) % mod) * div2) % mod)) % mod;
                }
                else {
                    tmp2 += ((((((subtree[j][k] * subtree[j][i - k]) % mod) * tmp) % mod))) % mod;
                }
                tmp2 %= mod;
                //std::cout << res << " ";
            }
            tmp2 *= subtree[0][j];
            tmp2 %= mod;
            res += tmp2;
            res %= mod;
        }
        std::cout << res << " ";
    }
    std::cout << endl;
    return 0;
}