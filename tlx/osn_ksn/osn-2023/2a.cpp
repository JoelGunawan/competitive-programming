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
  int n, p;
  cin >> n >> p;
  vector<int> one, two;
  for(int i = 1; i <= p; ++i) {
    int x, y;
    cin >> x >> y;
    if(x == 1)
      one.pb(y);
    else
      two.pb(y);
  }
  sort(one.begin(), one.end());
  sort(two.begin(), two.end());
  int q;
  cin >> q;
  while(q--) {
    int x, y;
    cin >> x >> y;
    // cout << one.end() - lower_bound(one.begin(), one.end(), max(x, y)) << " " << upper_bound(two.begin(), two.end(), min(x, y)) - two.begin() << endl;
    cout << ((int)(upper_bound(two.begin(), two.end(), min(x, y)) - two.begin()) + (one.end() - lower_bound(one.begin(), one.end(), max(x, y))) & 1) << endl;
  }
  return 0;
}