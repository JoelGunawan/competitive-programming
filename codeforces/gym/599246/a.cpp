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
  int r, c, n, p;
  cin >> r >> c >> n >> p;
  int a[r + 1][c + 1];
  for(int i = 1; i <= r; ++i) {
    for(int j = 1; j <= c; ++j) {
      cin >> a[i][j];
    }
  }
  set<int> s;
  vector<pair<int, int>> nxt = {mp(0, 1), mp(1, 0), mp(-1, 0), mp(0, -1)};
  for(int i = 1; i <= r; ++i) {
    for(int j = 1; j <= c; ++j) {
      if(a[i][j] <= p && a[i][j] != 0) {
        for(auto b : nxt) {
          if(i + b.fi < 1 || i + b.fi > r || j + b.se < 1 || j + b.se > c || a[i + b.fi][j + b.se] == 0)
            continue;
          s.insert(a[i + b.fi][j + b.se] - a[i][j] + p);
        }
      }
    }
  }
  while(s.size() && *s.begin() <= 0)
    s.erase(s.begin());
  while(s.size() && *--s.end() > n)
    s.erase(--s.end());
  // for(auto x : s) {
  //   cerr << x << " ";
  // }
  // cerr << endl;
  cout << s.size() << "/" << n - 1 << endl;
  return 0;
}