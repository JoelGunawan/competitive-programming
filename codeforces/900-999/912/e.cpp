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
const ll inf = 1e18;
void generate_nums(int idx, lll cur, vector<ll> &v, vector<ll> &ret) {
  if(idx == v.size()) {
    ret.pb(cur);
    return;
  }
  while(cur <= inf) {
    generate_nums(idx + 1, cur, v, ret);
    cur *= v[idx];
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  int p[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> p[i];
  ll k;
  cin >> k;
  if(n == 1) {
    // spec
    vector<lll> v;
    v.pb(1);
    while(v.back() <= 1e18) 
      v.pb(v.back() * p[1]);
    cout << (ll)v[k - 1] << endl;
    return 0;
  }
  sort(p + 1, p + n + 1);
  vector<ll> a1, a2;
  for(int i = 1; i <= n / 2; ++i)
    a1.pb(p[i]);
  for(int j = n / 2 + 1; j <= n; ++j)
    a2.pb(p[j]);
  vector<ll> v1, v2;
  generate_nums(0, 1, a1, v1);
  generate_nums(0, 1, a2, v2);
  ll l = 0, r = 1e18, ans = -1;
  sort(v1.begin(), v1.end());
  while(l <= r) {
    ll mid = (l + r) >> 1;
    ll cur = 0;
    for(auto x : v2) {
      // binser in v1
      cur += ub(v1.begin(), v1.end(), mid / x) - v1.begin();
    }
    if(cur >= k) {
      r = mid - 1, ans = mid;
    }
    else
      l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}