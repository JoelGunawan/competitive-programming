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
const ll lim = 200;
struct prefsum {
    ll a[lim];
    prefsum() {
        memset(a, 0, sizeof(a));
    }
    ll query(ll l, ll r) {
        if(l > r)
            return 0;
        else if(l == 0)
            return a[r];
        else
            return a[r] - a[l - 1];
    }
    void build() {
        for(ll i = 1; i < lim; ++i) {
            a[i] += a[i - 1];
        }
    }
};
ll c[200][200];    
ll n;
ll memo[200][200];
ll idx[200][200];
prefsum pref[200];
ll dp(ll l, ll r) {
    if(memo[l][r] != -1)
        return memo[l][r];
    else if(l > r)
        return 0;
    ll tmp = 0, res = LLONG_MAX, res_idx, sum = 0, arr[r + 1];
    memset(arr, 0, sizeof(arr));
    for(ll i = l; i <= r; ++i) {
        arr[i] += pref[i].query(0, l - 1);
        arr[i] += pref[i].query(r + 1, n - 1);
        sum += arr[i];
    }
    for(ll i = l; i <= r; ++i) {
        // range l itu dari l ke i - 1
        // range r itu dari i + 1 ke r
        ll tmp2 = dp(l, i - 1) + dp(i + 1, r) + sum - arr[i] + 2 * tmp + pref[i].query(l, r);
        //cout << "DE " << l << " " << r << " " << i << " " << dp(l, i - 1) << " " << dp(i + 1, r) << " " << 2 * tmp << " " << pref[i].query(l, r) << endl;
        if(tmp2 < res)
            res_idx = i, res = tmp2;
        if(i != r) {
            // tambah l
            tmp += pref[i].query(i + 1, r);
            // kurangi r
            tmp -= pref[i + 1].query(l, i);
        }
    }
    memo[l][r] = res;
    idx[l][r] = res_idx;
    return memo[l][r];
}
ll ans[200];
void f(ll l, ll r, ll par = -1) {
    if(l > r)
        return;
    ans[idx[l][r]] = par + 1;
    f(l, idx[l][r] - 1, idx[l][r]);
    f(idx[l][r] + 1, r, idx[l][r]);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    // cek antara range l1, r1 dan range l2, r2, itu ada berapa yang intersect
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            cin >> c[i][j];
        }
    }
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            pref[i].a[j] = c[i][j];
        }
        pref[i].build();
    }
    memset(memo, -1, sizeof(memo));
    // dp semua range
    // simpen current cost
    // dp[l][r] = dp[l][x - 1] + dp[x + 1][r]
    dp(0, n - 1);
    f(0, n - 1);
    for(ll i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}