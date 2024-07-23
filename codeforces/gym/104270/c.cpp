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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n;
    string s, t;
    cin >> n >> s >> t;
    s = " " + s;
    t = " " + t;
    vector<pair<int, int>> segs;
    int cur = 0;
    for(int i = 1; i <= n; ++i) {
      if(s[i] != t[i])  
        ++cur;
      else {
        if(cur > 0) {
          segs.pb(mp(i - cur, i - 1));
          cur = 0;
        }
      }
    }
    if(cur > 0) {
      segs.pb(mp(n - cur + 1, n));
      cur = 0;
    }
    if(segs.size() == 0) {
      cout << 1ll * n * (n + 1) / 2 << endl;
    }
    else if(segs.size() == 1) {
      cout << 2ll * (n - 1) << endl;
    }
    else if(segs.size() == 2) {
      cout << 6 << endl;
    }
    else {
      cout << 0 << endl;
    }
  }
  return 0;
}