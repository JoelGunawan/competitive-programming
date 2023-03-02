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
ll cross(pair<ll, ll> a, pair<ll, ll> b) {
    return a.fi * b.se - a.se * b.fi;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // area - perimeter / 2
    // perimeter only exists if (x_i - x_(i - 1) == 0 or y_i - y_(i - 1) == 0)
    int n;
    cin >> n;
    pair<ll, ll> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi >> a[i].se;
    ll area = 0, red = 0;
    for(int i = 0; i < n; ++i) {
        int nxt = (i + 1) % n;
        area += cross(a[i], a[nxt]);
        if(a[i].fi == a[nxt].fi || a[i].se == a[nxt].se) {
            red += abs(a[i].fi + a[i].se - a[nxt].fi - a[nxt].se);
        }
    }
    area = abs(area);
    if(red & 1) {
        area -= red / 2 + 1;
        cout << area << ".5" << endl;
    }
    else {
        cout << area - red / 2 << endl;
    }
    return 0;
}