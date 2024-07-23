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
int a[] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
int f(int x, int k) {
  if(k == 0)
    return x;
  if(x <= 1)
    return (k + x) & 1;
  string s = to_string(x);
  int nxt = 0;
  for(auto c : s) {
    nxt += a[c - '0'];
  }
  return f(nxt, k - 1);
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int x, k;
    cin >> x >> k;
    cout << f(x, k) << endl;
  }
  return 0;
}