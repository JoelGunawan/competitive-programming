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
    int n, k;
    cin >> n >> k;
    int zero[20];
    memset(zero, 0, sizeof(zero));
    ll res = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 19; j >= 0; --j) {
            if((1 << j) & i)
                ++zero[j];
        }
    }
    for(int i = 0; i < 20; ++i)
        res += 2 * min({k, zero[i], n - zero[i]}) * 1ll * (1 << i);
    cout << res << endl;
    return 0;
}