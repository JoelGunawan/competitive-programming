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
    int t;
    cin >> t;
    int c = 0;
    while(t--) {
        // average of left 2 and average of right 2
        ++c;
        int n;
        cin >> n;
        int x[n];
        cout << fixed << setprecision(9);
        for(int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        sort(x, x + n);
        if(n == 5) {
            cout << "Case #" << c << ": " << max((x[n - 1] + x[n - 3]) / 2.0 - (x[0] + x[1]) / 2.0, (x[n - 1] + x[n - 2]) / 2.0 - (x[0] + x[2]) / 2.0) << endl;
        }
        else {
            cout << "Case #" << c << ": " << (x[n - 1] + x[n - 2] - (x[0] + x[1])) / 2.0 << endl;
        }
    }
    return 0;
}