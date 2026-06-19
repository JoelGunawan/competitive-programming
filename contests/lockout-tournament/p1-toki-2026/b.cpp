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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  int a[n + 5], cnt[31];
  for (int i = 1; i <= n; ++i) cin >> a[i];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < 30; ++i) {
    for (int j = 1; j <= n; ++j) {
      if ((1 << i) & a[j]) ++cnt[i];
    }
  }

  int spec = 1;
  for (int i = 29; i >= 0; --i) {
    if (cnt[i] == 1) {
      for (int j = 1; j <= n; ++j) {
        if ((1 << i) & a[j]) {
          spec = j;
          break;
        }
      }
      break;
    }
  }

  cout << a[spec] << " ";

  for (int i = 1; i <= n; ++i) {
    if (i != spec) {
      cout << a[i] << " ";
    }
  }
  
  cout << endl;

  return 0;
}