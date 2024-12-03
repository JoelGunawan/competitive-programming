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
  ll n, d, s;
  cin >> n >> d >> s;
  ll max_pos = max(s, d / s * s * 2);
  if(max_pos > n) {
    ll last = n / s;
    if(last & 1) {
      last *= s;
      // check
      // a factor of n such that 
      ll res = (n / s - 1) * s; // always possible -> s -> (n / s - 1) / 2 * s -> n;
      assert(((n / s - 1) * s) - (n / s - 1) / 2 * s <= d);
      // cerr << "HERE" << endl;
      // assert that closest multiple of 2 is always reachable? 
      ll cur = last;
      for(int i = 2; i <= min((ll)1e6 + 5, last); ++i) {
        // last / i -> multiple of s
        // last -> multiple of s and multiple of i
        // diff between last and last / i is correct
        while(cur % i == 0)
          cur /= i;
        if(last % i == 0 && (last / i) % s == 0 && last - last / i <= d) {
          res = last;
        }
      }
      if(cur > 1 && last % cur == 0 && (last / cur) % s == 0 && last - last / cur <= d)
        res = last;
      res = max(res, s);
      cout << res << endl;
    }
    else {
      assert(n / s * s - n / s / 2 * s <= d);
      cout << n / s * s << endl;
    }
  }
  else {
    cout << max_pos << endl;
  }
  return 0;
}