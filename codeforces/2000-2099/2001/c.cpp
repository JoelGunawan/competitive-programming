#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// #define endl "\n"
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
int query(int x, int y) {
  cout << "? " << x << " " << y << endl;
  int val;
  cin >> val;
  return val;
}
void answer(vector<pair<int, int>> edges) {
  cout << "! ";
  for (auto &[u, v] : edges) {
    cout << u << " " << v << " ";
  }
  cout << endl;
  // exit(0);
}
void tc() {
  int n;
  cin >> n;
  set<int> known, unknown;
  known.insert(1);
  for (int i = 2; i <= n; ++i) unknown.insert(i);

  vector<pair<int, int>> edges;
  while (!unknown.empty()) {
    int new_elem = *unknown.begin();
    int old_elem = *known.begin();
    while (true) {
      int res = query(old_elem, new_elem);
      if (known.count(res)) {
        if (res == old_elem) {
          // adj
          known.insert(new_elem);
          unknown.erase(new_elem);
          edges.emplace_back(old_elem, new_elem);
          break;
        } else {
          // not adj, then move to res
          old_elem = res;
        }
      } else {
        new_elem = res;
      }
    }
  }
  answer(edges);
}
int main() {
  // ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) tc();
  return 0;
}