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
    int n, x;
    cin >> n >> x;
    int a[n + 1], b[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    // max -> 
    pair<int, int> p[n + 1];
    // fi -> diff, se -> idx
    for(int i = 1; i <= n; ++i)
        p[i].fi = a[i] - b[i], p[i].se = i;
    sort(p + 1, p + n + 1);
    ll cheap = 0;
    for(int i = 1; i <= x; ++i) {
       cheap += a[p[i].se];
    }
    for(int i = x + 1; i <= n; ++i) {
        cheap += min(a[p[i].se], b[p[i].se]);
    }
    ll exp = 0;
    reverse(p + 1, p + n + 1);
    for(int i = 1; i <= x; ++i) 
        exp += a[p[i].se];
    for(int i = x + 1; i <= n; ++i)
        exp += max(a[p[i].se], b[p[i].se]);
    cout << exp - cheap << endl;
    return 0;
}