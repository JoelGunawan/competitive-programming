// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
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
const int lim = 3e5 + 5;
void print(int n) {
  if(n < 1)
    n = 1;
  cout << n << endl;
}
bool input() {
  string x;
  cin >> x;
  if(x == "PAS") {
    exit(0);
  }
  else
    return x == "KEBESARAN" ? 1 : 0;
}
vector<int> v;
int idx(int n) {
  if(n < 1)
    return 0;
  return *--(--upper_bound(v.begin(), v.end(), n));
}
int main() {
  v = {1, 1};
  while(v.back() < 1e9) {
    v.pb(v.back() + v[v.size() - 2]);
  }
  int n, t;
  cin >> n >> t;
  int pad = 0, pr = n;
  int l = 1, r = n;
  print(idx(n));
  for(int cur = n - idx(n);;) {
    print(pad + idx(pr) + idx(cur));
    if(!input()) {
      pad += idx(pr);
      pr = cur;
      cur = cur - idx(cur);
      l = pad + 1;
    }
    else {
      r = pad + idx(pr) - 1;
      // between l to r
      pr = r - l + 1;
      print(pad + idx(r - l + 1));
      input();
      cur = pr - idx(pr);
    }
  }

  return 0;
}