// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
int mod = 1e9 + 7;
ll fact[200005];
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
ll combinmod(ll a, ll b) {
    return mul(fact[a], powmod(mul(fact[b], fact[a - b]), mod - 2));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    fact[0] = 1;
    for(int i = 1; i <= 2e5; ++i) {
        fact[i] = (1ll * fact[i - 1] * i) % mod;
    }
    int h, w, n;
    cin >> h >> w >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)  
        cin >> a[i].fi >> a[i].se;
    sort(a, a + n);
    ll ans[n];
    for(int i = 0; i < n; ++i) {
        ans[i] = combinmod(a[i].fi + a[i].se - 2, a[i].se - 1);
        for(int j = 0; j < i; ++j) {
            if(a[j].fi <= a[i].fi && a[j].se <= a[i].se) {
                ans[i] -= mul(ans[j], combinmod(a[i].fi - a[j].fi + a[i].se - a[j].se, a[i].fi - a[j].fi));
            }
        }
        ans[i] %= mod;
        if(ans[i] < 0)
            ans[i] += mod;
        //cout << a[i].fi << " " << a[i].se << " " << ans[i] << endl;
    }
    ll x = combinmod(h + w - 2, h - 1);
    for(int i = 0; i < n; ++i) {
        //cout << mul(ans[i], combinmod(h - a[i].fi + w - a[i].se, h - a[i].fi)) << " ";
        x -= mul(ans[i], combinmod(h - a[i].fi + w - a[i].se, h - a[i].fi));
    }
    //cout << endl;
    x %= mod;
    if(x < 0)
        x += mod;
    cout << x << endl;
    return 0;
}