#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
void tc() {
  int n;
  cin >> n;
  int a[2][n + 5];
  for(int i = 0; i < 2; ++i) {
    for(int j = 1; j <= n; ++j)
      cin >> a[i][j];
  }
  int latest[n + 1][2];
  memset(latest, 0, sizeof(latest));
  for(int i = 0; i < 2; ++i) {
    for(int j = 1; j <= n; ++j) {
      latest[a[i][j]][(i + j) & 1] = max(latest[a[i][j]][(i + j) & 1], j);
    }
  }
  int res = 0;
  for(int i = 1; i <= n; ++i) {
    res = max(res, min(latest[i][0], latest[i][1]));
  }
  for(int i = 0; i < 2; ++i) {
    for(int j = 1; j <= n; ++j) {
      if(latest[a[i][j]][(i + j) & 1] > j + 1) {
        res = max(res, j);
      }
    }
  }
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}