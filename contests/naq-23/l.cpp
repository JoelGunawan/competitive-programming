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
    int n, mn, mx;
    cin >> n >> mn >> mx;
    int a[n - 1];
    for(int i = 0; i < n - 1; ++i)
        cin >> a[i];
    sort(a, a + n - 1);
    if(mn > a[0] || mx < a[n - 2] || (a[0] > mn && a[n - 2] < mx))
        cout << -1 << endl, exit(0);
    else if(a[n - 2] != mx)
        cout << mx << endl;
    else if(a[0] != mn)
        cout << mn << endl;
    else {
        for(int i = mn; i <= mx; ++i)
            cout << i << endl;
    }
    return 0;
}