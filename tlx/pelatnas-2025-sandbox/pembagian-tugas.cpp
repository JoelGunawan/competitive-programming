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
  int a[n + 1], b[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i] >> b[i];
  vector<pair<int, int>> p;
  int tmp;
  cin >> tmp;
  bool pair[n + 1];
  memset(pair, 0, sizeof(pair));
  while(tmp--) {
    int u, v;
    cin >> u >> v;
    pair[u] = pair[v] = 1;
    p.pb(mp(u, v));
  }
  // use greedy? use something???
  // one, two -> "bonus" if we switch to 
  vector<int> one, two;
  ll cur = 0;
  for(int i = 1; i <= n; ++i) {
    if(!pair[i])
      cur += a[i], one.pb(b[i] - a[i]);
  }
  sort(one.begin(), one.end());
  for(auto x : p) {
    cur += a[x.fi] + a[x.se];
    two.pb(b[x.fi] + b[x.se] - a[x.fi] - a[x.se]);
  }
  sort(two.begin(), two.end());
  // assume use a lot of two first (max possible)
  // try to reduce count of two while increasing count of 1, if invalid stop
  int b_use = 0;
  int idxt = -1;
  for(int i = 0; i < min(n / 4, (int)two.size()); ++i) {
    b_use += 2;
    cur += two[i];
    idxt = i;
  }
  int idxo = -1;
  while(b_use < n / 2) {
    ++idxo;
    cur += one[idxo];
    ++b_use;
  }
  ll res = cur;
  while(idxt >= 0 && idxo + 2 < one.size()) {
    cur -= two[idxt];
    --idxt;
    cur += one[++idxo];
    cur += one[++idxo];
    res = min(res, cur);
  }
  cout << res << endl;
  return 0;
}