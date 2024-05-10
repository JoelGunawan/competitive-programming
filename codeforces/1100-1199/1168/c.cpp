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
  int n, q;
  cin >> n >> q;
  int a[n + 1];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int arr[20][n + 5];
  int min_nxt[20][n + 5];
  for(int i = 0; i <= 19; ++i) {
    fill(arr[i], arr[i] + n + 5, n + 5);
    fill(min_nxt[i], min_nxt[i] + n + 5, n + 5);
  }
  for(int i = n; i >= 1; --i) {
    for(int j = 0; j <= 19; ++j) {
      min_nxt[j][i] = min_nxt[j][i + 1];
      if((1 << j) & a[i]) {
        for(int k = 0; k <= 19; ++k) {
          // cout << "add nxt " << i << " " << min_nxt[j][i] << endl;
          arr[k][i] = min(arr[k][i], arr[k][min_nxt[j][i]]);
        }
        min_nxt[j][i] = i;
        arr[j][i] = i;
      }
    }
  }
  while(q--) {
    int l, r;
    cin >> l >> r;
    bool ans = 0;
    for(int i = 0; i <= 19; ++i) {
      if(((1 << i) & a[r]) && arr[i][l] <= r) {
        ans = 1;
      }
    }
    cout << (ans ? "Shi" : "Fou") << endl;
  }
}