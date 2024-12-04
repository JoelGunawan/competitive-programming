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
  string s;
  cin >> n >> s;
  // note:
  // 0 1 2 3 4 5 6 7 8  9 10 ...
  // X 1 3 1 7 1 3 1 15 1 3 ...
  // binlift: 
  // binlift[nd][0] = s[nd ^ 1]
  // binlift[nd][1] = binlift[nd][0] + s[nd ^ 2] + binlift[nd ^ 3][0]
  // binlift[nd][2] = binlift[nd][1] + s[nd ^ 4] + binlift[nd ^ 5][1]
  // binlift[nd][3] = binlift[nd][2] + s[nd ^ 8] + binlift[nd ^ 9][2]
  // for each binlift -> order by hashing
  // check smallest binlift[nd][i - 1]
  // if tie, check smallest s[nd ^ (1 << i)]
  // if tie, check smallest binlift[nd ^ 3][0]
  ll binlift[1 << n][n];
  const ll mul1 = 1e10, mul2 = 4e5;
  memset(binlift, 0, sizeof(binlift));
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < 1 << n; ++j) {
      if(i == 0)
        binlift[j][i] = s[j ^ 1];
      else
        binlift[j][i] = mul1 * binlift[j][i - 1] + mul2 * s[j ^ (1 << i)] + binlift[j ^ (1 << i)][i - 1];
      // cerr << binlift[j][i] << " ";
    }
    // cerr << endl;
    // compress
    vector<ll> v;
    for(int j = 0; j < 1 << n; ++j) 
      v.pb(binlift[j][i]);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for(int j = 0; j < 1 << n; ++j)
      binlift[j][i] = lb(v.begin(), v.end(), binlift[j][i]) - v.begin();
  }
  int mn = 256;
  for(auto c : s) {
    mn = min(mn, (int)c);
  }
  pair<ll, int> ans = mp((ll)1e18, (int)1e9);
  for(int i = 0; i < 1 << n; ++i) {
    if(s[i] == mn) {
      // cerr << binlift[i][n - 1] << " " << i << endl;
      ans = min(ans, mp(binlift[i][n - 1], i));      
    }
  }
  // cerr << ans.se << endl;
  for(int i = 0; i < 1 << n; ++i)
    cout << s[i ^ ans.se];
  cout << endl;
  return 0;
}