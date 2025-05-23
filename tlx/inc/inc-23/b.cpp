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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> p(n);
  for (int i = 0; i < n; ++i)
    cin >> p[i];
  for (int x = 0; x < n; ++x) {
    // sort p[0], p[1], .. p[x]
    vector<int> a;
    for (int i = 0; i <= x; ++i)
      a.push_back(p[i]);
    sort(a.begin(), a.end());
    // sorted p[0], p[1], ... p[x]
    int milk = m;
    int biscuit = k;
    bool possible = 1; // possible for x + 1 days?
    for (int i = 0; i <= x; ++i) {
      if (milk >= a[i]) {
        milk -= a[i];
      } else if (biscuit > 0) {
        --biscuit;
      } else {
        possible = 0;
        break;
      }
    }
    // not possible for x + 1 days -> output x
    if (!possible) {
      cout << x << endl;
      return 0;
    }
  }
  cout << n << endl;
  return 0;
}