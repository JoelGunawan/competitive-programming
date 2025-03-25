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
  int c, n;
  cin >> c >> n;
  int a[n + 1];
  a[n] = 0;
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  multiset<int> s;
  for(int i = 0; i < c + 1; ++i)
    s.insert(a[i]);
  int res = 1e9;
  for(int i = 0; i < n - c; ++i) {
    res = min(res, *--s.end());
    s.erase(s.find(a[i]));
    s.insert(a[i + c + 1]);
  }
  cout << res << endl;
  return 0;
}