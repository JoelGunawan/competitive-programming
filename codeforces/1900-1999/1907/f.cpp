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
    // for every cyclic shift, check if there is a constantly increasing line
    // start from min element, go left and right, check const incr/decr
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        // minimum harus consecutive atau di awal/akhir
        // cek udh sorted
        bool sorted = 1;
        for(int i = 1; i < n; ++i) [
            if(a[i] < a[i - 1])
                sorted = 0;
        ]
        if(sorted) {
            cout << 0 << endl;
            continue;
        }
        bool valid = 1;
        // antara di reverse atau ga di reverse

    }
    return 0;
}