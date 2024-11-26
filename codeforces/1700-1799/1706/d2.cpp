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
void tc() {
  int n, k;
  cin >> n >> k;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  int mx = 0;
  int total_mn = 1e9;
  for(int i = 1; i <= n; ++i) {
    if(i > 1 && a[i] == a[i - 1])
      continue;
    pq.push(mp(a[i] / k, i));
    mx = max(mx, a[i] / k);
    total_mn = min(total_mn, a[i]);
  }
  int res = 1e9;
  for(int mn = 0; mn <= total_mn; ++mn) {
    // cerr << mn << " " << pq.top().fi << endl;
    while(pq.size() && pq.top().fi < mn) {
      int idx = pq.top().se;
      int tmp = a[idx] / (pq.top().fi + 1);
      if(tmp == 0) {
        pq.pop();
        continue;
      }
      int nx = a[idx] / (a[idx] / (pq.top().fi + 1));
      // cerr << a[idx] / (pq.top().fi + 1) << endl;
      pq.push(mp(nx, idx));
      // cerr << mn << " " << pq.top().fi << " " << nx << " " << a[idx] << endl;
      mx = max(mx, nx);
      pq.pop();
    }
    res = min(res, mx - mn);
  }
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    tc();
  }
}