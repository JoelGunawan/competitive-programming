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
  int t;
  cin >> t;
  while(t--) {
    int x;
    cin >> x;
    string s = to_string(x);
    int res = -1;
    for(int i = 0; i <= x; ++i) {
      string t = to_string(i);
      bool ans = 0;
      for(auto c : s) {
        for (auto c2 : t) {
          if(c == c2)
            ans = 1;
        }
      }
      if(ans) {
        res = i;
        break;
      }
    }
    cout << res << endl;
  }
  return 0;
}