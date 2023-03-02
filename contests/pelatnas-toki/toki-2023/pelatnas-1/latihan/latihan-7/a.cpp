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
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll n;
    cin >> n;
    // tiap pair cari left sama 1, right sama 1, left dan right sama 1
    // left sama 2
    // right sama 2
    // jika w[j] = w[i] dan m[k] = m[i] maka m[j] != m[k] dan w[j] != w[k] karena diketahui
    // invalid = left sama 1 + right sama 1 - (left dan right sama 1) + left sama 2 + right sama 2
    ll wcnt[n + 1], mcnt[n + 1];
    memset(wcnt, 0, sizeof(wcnt));
    memset(mcnt, 0, sizeof(mcnt));
    ll inval = 0;
    pair<int, int> a[n + 1];
    for(int i = 1; i <= n; ++i) {
        int w, m;
        cin >> w >> m;
        a[i].fi = w, a[i].se = m;
        ++wcnt[w], ++mcnt[m];
    }
    for(int i = 1; i <= n; ++i) {
        int w = a[i].fi, m = a[i].se;
        inval += 1ll * (wcnt[w] - 1) * (mcnt[m] - 1);
        //inval += wcnt[i] * (wcnt[i] - 1) * (n - wcnt[i]) / 2 + mcnt[i] * (mcnt[i] - 1) * (n - mcnt[i]) / 2;
        //inval += 1ll * wcnt[i] * (wcnt[i] - 1) * (wcnt[i] - 2) / 6 + 1ll * mcnt[i] * (mcnt[i] - 1) * (mcnt[i] - 2) / 6;
    }
    ll total = 1ll * n * (n - 1) * (n - 2) / 6;
    total -= inval;
    cout << total << endl;
    return 0;
}