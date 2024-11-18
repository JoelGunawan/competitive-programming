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
string res = "0";
ll get_palindrome(ll n) {
  n = abs(n);
  if(n < 10)
    return n;
  else {
    // consider first n / 2 digits
    string s = to_string(n);
    for(int i = 0; i < s.size() / 2; ++i)
      s[s.size() - i - 1] = s[i];
    return stoll(s);
  }
}
void shift(ll n) {
  if(n == 0)
    return;
  ll x = get_palindrome(n);
  if(n < 0) {
    res += '+';
    res += to_string(x);
    res += "+0";
    shift(n + x);
  }
  else {
    res += '-';
    res += to_string(x);
    res += "-0";
    shift(n - x);
  }
}
ll a = 0, b = 0;
void diff(ll n) {
  if(n == 0)
    return;
  if(n & 1) {
    res += "+21-0";
    a += 21, b -= 12;
    diff(n - 33);
  }
  else {
    ll req = get_palindrome(n / 2);
    if(n > 0) {
      res += '+';
      res += to_string(req);
      res += "-0"; 
      a += req, b -= req;
      diff(n - 2 * req);
    }
    else {
      res += '-';
      res += to_string(req);
      res += "+0";
      a -= req, b += req;
      diff(n + 2 * req);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  ll p, q;
  cin >> p >> q;
  diff(p - q);
  shift(a - p);
  cout << res << endl;
  return 0;
}