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
  // find xor of entire array
  // we know xor of some sets
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int a[n + 1][n + 1];
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) {
        cin >> a[i][j];
      }
    }
    int res = 0;
    for(int i = 1; i <= n / 2; ++i) {
      pair<int, int> cur = mp(4 * i - 3, 1);
      while(cur.fi > n)
        --cur.fi, ++cur.se;
      vector<int> v;
      while(cur.fi > 0 && cur.se <= n) {
        v.pb(a[cur.fi][cur.se]);
        --cur.fi, ++cur.se;
      }
      // cerr << "LINE " << i << endl;
      // for(auto x : v)
      //   cerr << x << " ";
      // cerr << endl;
      for(int i = 0; i < v.size(); i += 2) 
        res ^= v[i];
    }
    // cerr << res << endl;
    for(int i = 1; i <= n / 2; ++i) {
      pair<int, int> cur = mp(n - 4 * i + 4, 1);
      while(cur.fi < 1) {
        ++cur.fi, ++cur.se;
      }
      vector<int> v;
      while(cur.fi <= n && cur.se <= n) {
        v.pb(a[cur.fi][cur.se]);
        ++cur.fi, ++cur.se;
      }
      for(int i = 0; i < v.size(); i += 2)
        res ^= v[i];

    }
    cout << res << endl;
  }
  return 0;
}