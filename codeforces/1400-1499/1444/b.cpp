// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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
int mod = 998244353;
int fact[300001];
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll combinmod(ll a, ll b) {
    return (((fact[a] * powmod(fact[b], mod - 2)) % mod) * powmod(fact[a - b], mod - 2)) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[2 * n];
    for(int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }
    fact[0] = 1;
    for(int i = 1; i <= 2 * n; ++i)
        fact[i] = (1ll * fact[i - 1] * i) % mod;
    sort(a, a + 2 * n);
    ll sum = 0;
    for(int i = 0; i < n; ++i)
        sum -= a[i];
    for(int i = n; i < 2 * n; ++i)
        sum += a[i];
    sum %= mod;
    cout << (((sum * combinmod(2 * n, n)) % mod) + mod) % mod << endl;   
    return 0;
}