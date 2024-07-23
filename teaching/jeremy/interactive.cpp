// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
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
int query(int l, int r) {
  cout << "? " << l << " " << r << endl;
  int x;
  cin >> x;
  return x;
}
void answer(vector<int> a) {
  cout << "! ";
  for(auto i : a) {
    cout << i << " ";
  }
  cout << endl;
}
int main() {
  int t, n, q;
  cin >> t >> n >> q;
  vector<int> ans;
  for(int i = 1; i <= n; ++i) {
    int que = query(1, i);
    ans.pb(que);
  }
  answer(ans);
  return 0;
}