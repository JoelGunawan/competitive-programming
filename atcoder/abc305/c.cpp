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
    char a[n + 1][m + 1];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    int l = 1e9, r = 0, u = 0, d = 1e9;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] == '#') {
                l = min(l, j);
                r = max(r, j);
                u = max(u, i);
                d = min(d, i);
            }
        }
    }
    //cout << l << " " << r << " " << u << " " << d << endl;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(j >= l && j <= r && i <= u && i >= d && a[i][j] != '#') {
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}