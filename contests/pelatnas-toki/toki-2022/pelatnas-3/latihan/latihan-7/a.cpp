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
    int n, x, m;
    cin >> n >> x >> m;
    int t[n];
    for(int i = 0; i < n; ++i)
        cin >> t[i];
    sort(t, t + n);
    int res1 = 1e9, res2 = t[n - 1];
    if(n <= 2) {
        if(n == 1)
            cout << t[0] << endl;
        else
            cout << t[1] << endl;
        exit(0);
    }
    else if(n <= 4) {
        cout << max(x + 1, t[n - 1]) << endl;
        exit(0);
    }
    int pos_sum[10000];
    memset(pos_sum, 0, sizeof(pos_sum));
    int total_sum = 0;
    pos_sum[0] = 1;
    for(int i = 4; i < n; ++i) {      
        if(t[i] <= x) {
            total_sum += x - t[i] + 1;
            for(int j = 9999; j >= x - t[i] + 1; --j) {
                pos_sum[j] |= pos_sum[j - (x - t[i] + 1)];
            }
        }
    }
    for(int i = 0; i < 10000; ++i) {
        if(pos_sum[i])
            res1 = min(res1, max(total_sum - i, i));
    }
    cout << max(x + 1 + res1, res2) << endl;
    return 0;
}