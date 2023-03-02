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
    int n, m;
    cin >> n >> m;
    int cur_pos = 1;
    ll res = 0;
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if(cur_pos >= x && cur_pos <= y)
            continue;
        else if(cur_pos > y) {
            res += cur_pos - y;
            cur_pos = y;
        }
        else {
            res += x - cur_pos;
            cur_pos = x;
        }
    }
    cout << res << endl;
    return 0;
}