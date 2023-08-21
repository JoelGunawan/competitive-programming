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
    int n, d;
    cin >> n >> d;
    char grid[n + 1][d + 1];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= d; ++j)
            cin >> grid[i][j];
    int res = 0;
    for(int i = 1; i <= d; ++i) {
        // coba dr day 
        for(int j = i; j <= d; ++j) {
            bool found = 1;
            for(int k = 1; k <= n; ++k) {
                if(grid[k][j] == 'x')
                    found = 0;
            }
            if(!found)
                break;
            else
                res = max(res, j - i + 1);
        }
    }
    cout << res << endl;
    return 0;
}