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
    int n, t;
    cin >> n >> t;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int lpointer = 0, rpointer = 0, sum = a[0], res = 0;
    while(rpointer < n) {
        while(rpointer + 1 < n && sum + a[rpointer + 1] <= t)
            sum += a[rpointer + 1], rpointer++;
        if(sum <= t)
            res = max(res, rpointer - lpointer + 1);
        sum -= a[lpointer];
        sum += a[rpointer + 1];
        ++lpointer, ++rpointer;
    }
    cout << res << endl;
    return 0;
}