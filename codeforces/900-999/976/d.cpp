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
  int d[n];
  for(int i = 0; i < n; ++i)
    cin >> d[i];
  int v = d[n - 1] + 1; // number of vertices
  int use[v + 1], use_inv[v + 1];
  fill(use, use + v + 1, v);
  fill(use_inv, use_inv + v + 1, v);
  for(int i = 0; i < n; ++i) {
    // given d[i] -> v - d[i]
    if(d[i] <= v / 2)
      continue;
    int diff = v - d[i];
    use[diff - 1] = diff - 1;
  }
  for(int i = v - 1; i >= 0; --i)
    use[i] = min(use[i], use[i + 1]);
  // for(int i = 1; i <= v; ++i)
  //   cerr << use[i] << " ";
  // cerr << endl;
  int parity = 0;
  for(int i = 0; i < n; ++i) {
    parity ^= (d[i] & 1);
    for(int j = d[i]; j <= v; ++j) {
      --use[j];
    }
  }
  for(int i = v - 1; i >= 0; --i)
    use[i] = min(use[i], use[i + 1]);
  vector<int> new_degs;
  for(int i = 0; i < n; ++i) {
    int cur = d[i];
    // add max amount of cur possible
    while(use[cur]) {
      // cerr << cur << " " << use[cur] << endl;
      parity ^= cur & 1;
      for(int j = cur; j <= v; ++j)
        --use[j];
      new_degs.pb(cur);
    }
    for(int i = v - 1; i >= 0; --i)
      use[i] = min(use[i], use[i + 1]);
  }
  if(parity) {
    // can change even -> odd or odd -> even
    // try both?
    // choose something idk man im stressed
    // try and move 
    int occur[v + 1];
    memset(occur, 0, sizeof(occur));
    for(auto x : new_degs)
      ++occur[x];
    for(int i = 1; i <= v; ++i) {
      if(occur[i] >= 2) {
        // find next d[j] with different parity
      }
    }
  }
  // based on given degs, we can find the answer
  for(int i = 0; i < n; ++i)
    new_degs.pb(d[i]);
  // all new_degs found
  assert(new_degs.size() == v);
  int deg[v + 1];
  memset(deg, 0, sizeof(deg));
  for(int i = 0; i < v; ++i)
    deg[i + 1] = new_degs[i];
  vector<pair<int, int>> ans;
  // for(auto x : new_degs)
  //   cerr << x << " ";
  // cerr << endl;
  while(true) {
    pair<int, int> mx = mp(0, 0);
    vector<pair<int, int>> a;
    for(int i = 1; i <= v; ++i)
      if(deg[i])
        a.pb(mp(deg[i], i));
    sort(a.begin(), a.end());
    if(a.empty())
      break;
    // cerr << a.back().fi << " " << a.back().se << endl;
    int cur = a.back().se, am = a.back().fi;
    a.pop_back();
    for(int i = 1; i <= am; ++i) {
      int x = a.back().se;
      a.pop_back();
      --deg[x];
      ans.pb(mp(cur, x));
    }
    deg[cur] = 0;
  }
  cout << ans.size() << endl;
  for(auto x : ans)
    cout << x.fi << " " << x.se << endl;
  return 0;
}