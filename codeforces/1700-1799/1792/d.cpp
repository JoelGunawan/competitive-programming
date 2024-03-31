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
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a[n + 1];
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) {
        int x;
        cin >> x;
        --x;
        a[i].pb(x);
      }
    }
    map<vector<int>, bool> exist;
    for(int i = 1; i <= n; ++i) {
      vector<int> req(m, -1);
      for(int j = 0; j < m; ++j) {
        req[a[i][j]] = j;
      }
      vector<int> cur;
      for(int j = 0; j < m; ++j) {
        cur.pb(req[j]);
        exist[cur] = 1;
      }
    }
    int res[n + 1];
    memset(res, 0, sizeof(res));
    for(int i = 1; i <= n; ++i) {
      int res = 0;
      vector<int> cur;
      for(int j = 0; j < m; ++j) {
        cur.pb(a[i][j]);
        if(exist[cur]) {
          res = max(res, j + 1);
        }
        else
          break;
      }
      cout << res << " ";
    }
    cout << endl;
  }
  return 0;
}