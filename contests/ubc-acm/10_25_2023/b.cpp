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
void solve() {
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        a[i] %= k;
    // k = 4 -> special case
    if(k == 4) {
        int one = 0, two = 0, three = 0;
        for(int i = 1; i <= n; ++i) {
            if(a[i] == 0) {
                cout << 0 << endl;
                return;
            }
            else if(a[i] == 1) {    
                ++one;
            }
            else if(a[i] == 2)
                ++two;
            else
                ++three;
        }
        if(two >= 2)
            cout << 0 << endl;
        else if(three)
            cout << 1 << endl;
        else if(two == 1 && one > 0)
            cout << 1 << endl;
        else
            cout << 2 << endl;
        return;
    }
    int mn = k - 1;
    for(int i = 1; i <= n; ++i) {
        if(a[i] == 0)
            mn = 0;
        else
            mn = min(mn, k - a[i]);
    }
    cout << mn << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}