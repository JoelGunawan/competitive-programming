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
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll n;
    cin >> n;
    ll a[n + 1];
    for(ll i = 1; i <= n; ++i)
        cin >> a[i];
    ll cnt[2 * n + 5];
    memset(cnt, 0, sizeof(cnt));
    for(ll i = 1; i <= n; ++i)
        a[i] = min(a[i], 2 * n - 1), ++cnt[a[i]];
    ll free = 0, cur = 0, taken = 0, res = 1;
    for(ll i = 1; i <= 2 * n - 1; ++i) {
        cur += cnt[i];
        if(cnt[i] == 0)
            ++free;
        if(cur >= free + 2) {
            // ambil langsung
            // dari pr          
            res = (res * (cur)) % mod;
            ++free;
            --cur;
            ++taken;
        }
    }
    while(taken < n) {
        res = (res * (n - taken)) % mod;
        ++taken;
    }
    cout << res % mod << endl;
    return 0;
}