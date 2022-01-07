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
ll mod = 998244353, fact[5001], invfact[5001];
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll combinmod(int a, int b) {
    return (((1ll * fact[a] * invfact[b]) % mod) * invfact[a - b]) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0] = 1;
    invfact[0] = powmod(fact[0], mod - 2);
    for(int i = 1; i <= 5000; ++i) {
        fact[i] = (1ll * fact[i - 1] * i) % mod;
        invfact[i] = powmod(fact[i], mod - 2);
    }
    int n, k;
    cin >> n >> k;
    char a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    ll res = 1;
    int pref_sum[n + 1];
    pref_sum[0] = 0;
    for(int i = 1; i <= n; ++i) {
        pref_sum[i] = pref_sum[i - 1] + a[i] - '0';
    }
    if(pref_sum[n] < k) {
        cout << 1 << endl;
        return 0;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < i; ++j) {
            if(pref_sum[i] - pref_sum[j - 1] <= k) {
                // cek di tengah ada berapa 1, jadi kombinnya berapa
                int cnt = pref_sum[i] - pref_sum[j - 1];
                if(a[i] == '0')
                    --cnt;
                if(a[j] == '0')
                    --cnt;
                if(cnt >= 0 && i - j - 1 >= cnt)
                    res = (res + combinmod(i - j - 1, cnt)) % mod;
            }
        }
    }
    cout << res << endl;
    return 0;
}