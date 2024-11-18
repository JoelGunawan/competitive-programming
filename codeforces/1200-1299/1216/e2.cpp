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
lll calc(lll con, lll n, lll mul) {
  return con * n + mul * n * (n + 1) / 2;
}
ll power(ll a, ll b) {
  if(b == 0)
    return 1;
  else {
    ll tmp = power(a, b >> 1);
    tmp = (tmp * tmp);
    return b & 1 ? (tmp * a) : tmp;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int q;
  cin >> q;
  // build: 
  // 1, 12, 123, 1234, ... -> 1 + 2 + 3 + ... + 9
  // 12345678910, 1234567891011, ... -> 11 + 13 + ... + (as much as 90 times)
  // 9 -> 90 -> 900
  // const * n + mul * n * (n + 1) / 2
  vector<ll> v = {0};
  vector<ll> len = {0};
  ll cnt = 9;
  ll last_len = 0;
  // 0 -> 9 -> 9 + 90 * 2 -> 9 + 90 * 2 + 900 * 3
  // here is also wrong then :melting_face:
  // need to use length of last as cons, not length of total
  // 9
  // 9 + 2 * 10
  while(calc(last_len, cnt, v.size()) + v.back() <= 1e18) {
    v.pb(calc(last_len, cnt, v.size()) + v.back());
    cnt *= 10;
    ll curadd = 9;
    for(int i = 2; i < v.size(); ++i)
      curadd *= 10;
    last_len += curadd * (v.size() - 1);
    len.pb(last_len);
  }
  // for(auto x : v)
  //   cout << x << " ";
  // cout << endl;
  // for(auto x : len)
  //   cout << x << " ";
  // cout << endl;
  while(q--) {
    ll k;
    cin >> k;
    int digits = 0;
    for(int i = 0; i < v.size(); ++i) {
      if(k > v[i])
        digits = i;
    } 
    // cerr << k << endl;
    k -= v[digits];
    // NO, cons is length of ONLY LAST
    ll cons = len[digits];
    ll l = 0, r = power(10, digits + 2), ans = -1;
    // cerr << l << " " << r << endl;
    while(l <= r) {
      ll mid = (l + r) >> 1;
      if(calc(cons, mid, digits + 1) < k)
        l = mid + 1, ans = mid;
      else
        r = mid - 1;
    }
    // based on cumulative length -> we can determine what digit count
    // after determine what digit count -> determine which number
    // after determine which number -> determine position
    // the k-th digit of this sequence, find the digit count first
    // cerr << ans << " " << k << endl;
    k -= calc(cons, ans, digits + 1);
    // cerr << k << endl;
    // get the count of digits
    int dig;
    for(int i = 0; i < len.size(); ++i) {
      if(k > len[i])
        dig = i + 1;
    }
    k -= len[dig - 1];
    // cerr << k << endl;
    l = power(10, dig - 1), r = power(10, dig) - 1, ans = -1;
    // cerr << "HERE" << endl;
    // find which one it is
    while(l <= r) {
      ll mid = (l + r) >> 1;
      // dig * x
      if(k > (lll)dig * (mid - power(10, dig - 1)))
        l = mid + 1, ans = mid;
      else
        r = mid - 1;
    }
    // cerr << "GOT " << k << " " << ans << endl;
    // cout << ans << endl;
    k -= (ans - power(10, dig - 1)) * dig;
    // cout << k << endl;
    string str = to_string(ans);
    // cerr << dig << " " << str << endl;
    cout << str[k - 1] << endl;
  }
  return 0;
}