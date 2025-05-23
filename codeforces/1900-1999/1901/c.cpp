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
void tc() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    // 0/1
    // consider only max and min elements
    // everything else doesnt matter
    int mn = 1e9, mx = 0;
    for(int i = 1; i <= n; ++i) {
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    vector<int> ops;
    while(mn != mx) {
        if(mn & 1)
            ops.pb(1), mn = (mn + 1) / 2, mx = (mx + 1) / 2;
        else
            ops.pb(0), mn /= 2, mx /= 2;
    }
    cout << ops.size() << endl;
    if(ops.size() <= n) {
        for(auto i : ops)
            cout << i << " ";
        cout << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}