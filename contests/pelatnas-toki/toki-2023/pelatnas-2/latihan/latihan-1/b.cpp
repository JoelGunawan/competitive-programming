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
    int sz = 100;
    int a[101][101];
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= sz; ++i) {
        for(int j = i + 1; j <= sz; ++j) {
            a[i][j] = 100;
        }
    }
    // sisanya 100 kecuali explicitly stated
    a[1][2] = 1, a[1][3] = 1, a[1][4] = 1;
    a[2][3] = 1;
    // 4 -> 5
    // 3 -> 6
    // 6 -> 7
    // 5 -> 8
    for(int i = 5; i <= sz; ++i) {
        if(i & 1)
            a[i - 1][i] = 1;
        else
            a[i - 3][i] = 1;
    }
    cout << sz << endl;
    for(int i = 1; i <= sz; ++i) {
        for(int j = i + 1; j <= sz; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}