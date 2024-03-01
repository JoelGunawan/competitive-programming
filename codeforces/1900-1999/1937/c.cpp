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
int interact(int a, int b, int c, int d) {
  --a, --b, --c, --d;
  cout << "? " << a << " " << b << " " << c << " " << d << endl;
  char x;
  cin >> x;
  if(x == '<')
    return -1;
  else if(x == '=')
    return 0;
  else
    return 1;
}
int main() {
  // find min elem
  // then find values of all elems
  // then find max xor brute force n^2
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int mx = 1;
    for(int i = 2; i <= n; ++i) {
      int x = interact(mx, mx, i, i);
      if(x == -1)
        mx = i;
    }
    vector<int> val;
    int curmx = 1;
    for(int i = 1; i <= n; ++i) {
      int x = interact(mx, curmx, mx, i);
      if(x == 0)
        val.pb(i);
      else if(x == -1) {
        val.clear(), curmx = i;
        val.pb(i);
      }
    }
    int mn = val[0];
    for(auto x : val) {
      int s = interact(mn, mn, x, x);
      if(s == 1)
        mn = x;
    }
    cout << "! " << mn - 1 << " " << mx - 1 << endl;
  }
  return 0;
}