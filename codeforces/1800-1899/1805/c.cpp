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
ll sqr(ll x) {
  return x * x;
}
const int lim = 1e9;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
      cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = 1; i <= m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      // le -> less than or equal
      // be -> bigger than or equal
      int le = 1e9, be = 1e9;
      bool ans = 0;
      // find closest to b
      if(ub(v.begin(), v.end(), b) != v.begin())
        le = *--ub(v.begin(), v.end(), b);
      if(lb(v.begin(), v.end(), b) != v.end())
        be = *lb(v.begin(), v.end(), b);
      if(le != lim && sqr(b - le) < 4ll * a * c) {
        cout << "YES" << endl;
        cout << le << endl;
      }
      else if(be != lim && sqr(b - be) < 4ll * a * c) {
        cout << "YES" << endl;
        cout << be << endl;
      }
      else {
        cout << "NO" << endl;
      }
    }
    cout << endl;
  }
  return 0;
}