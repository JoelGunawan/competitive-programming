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
    // a mod b -> 0 ... a / 2
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a.pb(x);
    }
    // either smallest is gcd, or between 0 ... a / 2 + a mod 2 - 1 where a is the smallest elem is the answer
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = a.size();
    int mn = 1e9 + 5;
    for(int i = 1; i < a.size(); ++i) {
        mn = min(mn, a[i] / 2);
    }
    if(mn >= a[0])
        cout << a[0] << endl;
    else
        cout << max(1, a[0] / 2) << endl;
    return 0;
}