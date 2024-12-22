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
ll mod(ll a) {
  a %= 5;
  if(a < 0)
    a += 5;
  return a;
}
ll roundup(ll a) {
  if(a < 0 && a % 5)
    return a / 5 - 1;
  else
    return a / 5;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  ll n, k, b, c;
  cin >> n >> k >> b >> c;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  int idx = 0;
  sort(a + 1, a + n + 1);
  set<int> s[5];
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j < 5; ++j)
      s[mod(a[i] + j)].ins(a[i] + j);
  }
  ll res = 1e18;
  ll cost5 = min(5 * c, b);
  queue<ll> q[5];
  // maintain the actual occurence
  for(int i = 0; i < 5; ++i) {
    for(int i = 0; i < 5; ++i) {
      while(q[i].size())
        q[i].pop();
    }
    int idx = 0, cnt = 0;
    ll cost = 0;
    for(auto t : s[i]) {
      while(idx < n && a[idx + 1] <= t) {
        ++idx;
        q[mod(a[idx])].push((- (mod(t) < mod(a[idx]) ? 1 : 0) - roundup(a[idx])) * cost5 + mod(t - a[idx]) * c);
        ++cnt;
        cost += (- (mod(t) < mod(a[idx]) ? 1 : 0) - roundup(a[idx])) * cost5 + mod(t - a[idx]) * c;
        // cerr << "ADDED " << t << " " << (- (mod(t) < mod(a[idx]) ? 1 : 0) - a[idx] / 5) << " " << cost5 << " " << mod(t - a[idx]) << " " << c << endl;
      }
      if(cnt < k)
        continue;
      while(cnt > k) {
        ll mx = -1e18, mxidx = 0;
        for(int i = 0; i < 5; ++i)
          if(q[i].size() && q[i].front() > mx)
            mx = q[i].front(), mxidx = i;
        cost -= q[mxidx].front();
        --cnt;
        q[mxidx].pop();
      }
      res = min(res, 1ll * cnt * roundup(t) * cost5 + cost);
    }
  }
  cout << res << endl;
  return 0;
}