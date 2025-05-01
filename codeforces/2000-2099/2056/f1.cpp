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
const int bsz = 205;
bitset<bsz> add(bitset<bsz> a, bitset<bsz> b) {
  int carry = 0;
  for(int i = 0; i < bsz; ++i) {
    int res = a[i] + b[i] + carry;
    a[i] = res & 1;
    carry = (bool)(res & 2);
  }
  return a;
}
bitset<bsz> sub(bitset<bsz> a, bitset<bsz> b) {
  b = ~b;
  b = add(b, bitset<bsz>(1));
  return add(a, b);
}
bool submask(bitset<bsz> a, bitset<bsz> b) {
  for(int i = 0; i < bsz; ++i)
    if(a[i] && !b[i])
      return false;
  return true;
}
void tc() {
  int k, m;
  cin >> k >> m;
  string s;
  cin >> s;
  bitset<bsz> n(s);
  s.pop_back();
  bitset<bsz> half(s);
  // t is n / 2
  // n is odd
  int parity[m];
  // distinct = 1 case
  fill(parity, parity + m, 1);
  // distinct = 2 case
  if (k > 1 && n[0]) {
    // odd case
    bitset<bsz> tmp = sub(n, bitset<bsz>(1));
    bool larger = !submask(half, tmp);
    if(larger) {
      for(int i = 1; i < m; i += 2)
        parity[i] ^= 1;
    }
  }
  else if(k > 1 && !n[0]) {
    // even case
    bool smaller = submask(half, n);
    bitset<bsz> tmp = sub(n, bitset<bsz>(1));
    bool larger = !submask(half, tmp);
    if(smaller) {
      for(int i = m - 2; i >= 0; i -= 2)
        parity[i] ^= 1;
    }
    if(larger) {
      for(int i = 1; i < m; i += 2)
        parity[i] ^= 1;
    }
  }
  // distinct = 3 case
  bool val = 0;
  val ^= (k > 2 && n[0] && n[1]); // n!/((n - 3)!2!1!)
  val ^= (k > 3 && n[0] && n[2]); // n!/((n - 5)!4!1!)
  val ^= (k > 3 && n[1] && n[2]); // n!/((n - 6)!4!2!)
  if(val) {
    // larger can be odd
    for(int i = 1; i < m; ++i) {
      if((1ll * i * (i - 1) / 2) & 1) {
        parity[i] ^= 1;
      }
    }
  }
  int res = 0;
  for(int i = 1; i < m; ++i)
    if(parity[i])
      res ^= i;
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    tc();
  }
  return 0;
}