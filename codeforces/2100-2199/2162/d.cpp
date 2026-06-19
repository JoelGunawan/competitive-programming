#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
ll query1(int l, int r) {
  cout << "1 " << l << " " << r << endl;
  ll x;
  cin >> x;
  return x;
}
ll query2(int l, int r) {
  cout << "2 " << l << " " << r << endl;
  ll x;
  cin >> x;
  return x;
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    // binser
    int l = 1, r = n, ansl = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (query1(1, mid) != query2(1, mid)) {
        r = mid - 1;
      } else {
        ansl = mid, l = mid + 1;
      }
    }

    int diff = query2(1, n) - query1(1, n);

    cout << "! " << ansl + 1 << " " << ansl + diff << endl;
  }
  
  return 0;
}