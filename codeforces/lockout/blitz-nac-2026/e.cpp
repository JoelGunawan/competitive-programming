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
  int n, k;
  cin >> n >> k;
  string s; cin >> s;

  string a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> locs[26];
  for (int i = 0; i < s.size(); ++i) {
    locs[s[i] - 'a'].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    ll res = 0;
    for (int j = 0; j < a[i].size(); ++j) {
      int id = a[i][j] - 'a';
      int nx = lb(locs[id].begin(), locs[id].end(), j) - locs[id].begin();
      int pr = nx;
      --pr;
      int pot = 1e9;
      if (locs[id].empty()) {
        res += a[i].size();
        continue;
      }
      if (pr >= 0 && pr < locs[id].size()) {
        // cerr << j << " " << pr << " " << locs[id][pr] << endl;
        pot = min(pot, abs(j - locs[id][pr]));
      } 
      --pr;
      if (pr >= 0 && pr < locs[id].size()) {
        // cerr << j << " " << pr << " " << locs[id][pr] << endl;
        pot = min(pot, abs(j - locs[id][pr]));
      } 
      if (nx < locs[id].size() && nx >= 0) {
        // cerr << "NX " << j << " " << nx << " " << locs[id][nx] << endl;
        pot = min(pot, abs(locs[id][nx] - j));
      }
      ++nx;
      if (nx < locs[id].size() && nx >= 0) {
        // cerr << "NX " << j << " " << nx << " " << locs[id][nx] << endl;
        pot = min(pot, abs(locs[id][nx] - j));
      }
      res += pot;
    }
    cout << res << endl;
  }
  return 0;
}