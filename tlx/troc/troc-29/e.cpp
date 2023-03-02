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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    ll a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ll pref[n + 1], suff[n + 2];
    pref[0] = 0, suff[n + 1] = 0;
    for(int i = 1; i <= n; ++i)
        pref[i] = __gcd(pref[i - 1], a[i]);
    for(int i = n; i >= 1; --i)
        suff[i] = __gcd(suff[i + 1], a[i]);
    ll res = 0;
    for(int i = 1; i <= n; ++i)
        res = max(res, __gcd(pref[i - 1], suff[i + 1]) + a[i]);
    cout << res << endl;
    return 0;
}