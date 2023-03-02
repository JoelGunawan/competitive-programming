// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
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
    int n;
    cin >> n;
    bool a[n][n];
    memset(a, 0, sizeof(a));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) {
            char x;
            cin >> x;
            a[i][j] = x == '1';
        }
    // memo -> fi: cur, se: origin
    // memo2 -> fi: cur, se: origin
    unsigned long long memo[n][47];
    memset(memo, 0, sizeof(memo));
    unsigned long long ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) {
            if(i == j)
                continue;
            if(a[i][j]) {
                memo[j][i / 64] += (unsigned long long)1 << (unsigned long long)(i % 64);
            }
            //cout << j << " " << i / 64 << " " << memo[j][i / 64] << " " << memo2[j][i / 64] << endl;
        }
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(a[i][j]) {
                //cout << "TEST" << endl;
                for(int k = 0; k < 47; ++k) {
                    ans += __builtin_popcountll(memo[i][k] & memo[j][k]);
                }
            }
        }
    }   
    cout << ans / 3 << endl;
    return 0;
}