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
  // star init -> bob win
  // can make to star in 1 move -> alice win
  // else -> draw
  int degree[n + 1];
  memset(degree, 0, sizeof(degree));
  vector<pair<int, int>> adj;
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj.pb(mp(u, v));
    ++degree[u], ++degree[v];
  }
  if(n == 2) {
    cout << "Bob" << endl;
    return 0;
  }
  int nl = 0;
  for(int i = 1; i <= n; ++i)
    if(degree[i] != 1)
      ++nl;
  cout << ((nl & 1) ? "Bob" : "Alice") << endl;
  return 0;
}