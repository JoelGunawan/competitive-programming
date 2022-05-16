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
//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q;
    cin >> n >> q;
    pair<ll, ll> a[n + 1];
    ll cur_sum = 0;
    for(ll i = 1; i <= n; ++i)
        cin >> a[i].fi, a[i].se = 0, cur_sum += a[i].fi;
    ll last_change, last_change_time = -1, inc = 0;
    while(q--) {
        ++inc;
        ll t;
        cin >> t;
        if(t == 1) {
            ll i, x;
            cin >> i >> x;
            if(a[i].se > last_change_time)
                cur_sum += x - a[i].fi;
            else
                cur_sum += x - last_change;
            a[i].se = inc;
            a[i].fi = x;
            cout << cur_sum << endl;
        }
        else {
            ll x;
            cin >> x;
            last_change = x;
            last_change_time = inc;
            cur_sum = 1ll * x * n;
            cout << cur_sum << endl;
        }
    }
    return 0;
}