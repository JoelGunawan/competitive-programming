// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
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
int mod = 1e9 + 7;
int pow2[3005];
ll powmod(ll a, ll b) {
  if(b == 0)
    return 1;
  else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
ll mul(ll a, ll b) {
  return (a * b) % mod;
}
ll sub(ll a, ll b) {
  return (((a - b) % mod) + mod) % mod;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  pow2[0] = 1;
  for(int i = 1; i <= 3000; ++i) {
    pow2[i] = (pow2[i - 1] << 1) % mod;
  }
  // split left and right
  // obs: add 1 elem if prev dist is x, then next dist has to be x + 1, then another pair
  // A . A .. A . A -> 2 dots
  // if non decr, then decr -> add by 1
  // problem: x till 1e9
  // find count of subsets where last dist is x
  // for each i, j find whether it adds a gap or not, find count of subsets
  int n;
  cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  ll res = 0;
  for(int i = 1; i <= n; ++i) {
    int idxl = i, idxr = i;
    for(int j = i + 1; j <= n; ++j) {
      idxr = max(idxr, j);
      int dist = a[j] - a[i];
      while(idxl > 1 && a[i] - a[idxl - 1] <= dist)
        --idxl;
      // i go left: a[i] - a[x] <= dist
      ll cur = 1;
      if(idxl != i)
        cur = mul(pow2[idxl - 1], sub(pow2[i - idxl], 1));
      else
        cur = 0;
      while(idxr < n && a[idxr + 1] - a[j] < dist)
        ++idxr;
      // j go right: a[x] - a[j] < dist
      if(idxr != j)
        cur = mul(cur, mul(pow2[n - idxr], sub(pow2[idxr - j], 1)));
      else
        cur = 0;
      res += cur;
    }
  }
  cout << ((res % mod) + sub(pow2[n], n + 1)) % mod << endl;
  return 0;
}