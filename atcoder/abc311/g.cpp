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
    // cari O(N^3)
    // coba maks grid dengan syarat minimum >= x
    int n, m;
    cin >> n >> m;
    int grid[n + 1][m + 1];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> grid[i][j];
    // simpan prefix maximum dan minimum
    // nanti bfs
    // 
    return 0;
}