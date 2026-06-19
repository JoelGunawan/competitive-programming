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
  int a[n + 5], b[n + 5];
  memset(a, -1, sizeof(a));
  memset(b, -1, sizeof(b));
  
  if (n & 1) {
    for(int i = 1; i <= n / 2 + (n & 1); ++i) {
      a[2 * i - 1] = 3 * i - 1;
      b[2 * i - 1] = 3 * i;
    }
  
    for(int i = 1; i <= n / 2; ++i) {
      a[2 * i] = 2 * n - i + 1;
      b[2 * i] = 3 * i + 1;
    }

    b[n] = 1;
  } else {
    for(int i = 1; i <= n / 2; ++i) {
      a[2 * i - 1] = 3 * i - 2;
      b[2 * i - 1] = 3 * i - 1;
    }
  
    for(int i = 1; i <= n / 2; ++i) {
      a[2 * i] = 2 * n - i + 1;
      b[2 * i] = 3 * i;
    }
  }

  for(int i = 1; i <= n; ++i)
    cout << a[i] << " ";
  cout << endl;
  for(int i = 1; i <= n; ++i)
    cout << b[i] << " ";
  cout << endl;
  return 0;
}