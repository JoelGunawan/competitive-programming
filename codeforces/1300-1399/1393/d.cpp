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
    char a[n + 2][m + 2];
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) 
        cin >> a[i][j];
    }
    // observe that we can count top and bottom separately
    // then it is constructive which is easier at each point, find max top half and max bottom half
    //   a -> here maintain how much is max top half (by height so it's easier)
    // a a a -> here also maintain how much is max top half
    int l[n + 1][m + 1], r[n + 1][m + 1];
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) {
        if(a[i][j] == a[i][j - 1])
          l[i][j] = l[i][j - 1] + 1;
        else
          l[i][j] = 1;
      }
      for(int j = m; j >= 1; --j) {
        if(a[i][j] == a[i][j + 1]) 
          r[i][j] = r[i][j + 1] + 1;
        else
          r[i][j] = 1;
      }
    }
    int top[n + 1][m + 1], bottom[n + 1][m + 1];
    memset(bottom, 0, sizeof(bottom));
    memset(top, 0, sizeof(top));
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) {
        // check top bisa berapa
        if(a[i - 1][j] == a[i][j]) {
          top[i][j] = min({top[i - 1][j] + 1, l[i][j], r[i][j]});
        }
        else {
          top[i][j] = 1;
        }
      }
    }
    for(int i = n; i >= 1; --i) {
      for(int j = 1; j <= m; ++j) {
        // check bottom bisa berapa
        if(a[i + 1][j] == a[i][j]) {
          bottom[i][j] = min({bottom[i + 1][j] + 1, l[i][j], r[i][j]});
        }
        else {
          bottom[i][j] = 1;
        }
      }
    }
    ll res = 0;
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) {
        //cout << "DEBUG2 " << i << " " << j << " " << bottom[i][j] << " " << top[i][j] << endl;
        res += min(bottom[i][j], top[i][j]);
      }
    }
    cout << res << endl;
    return 0;
}