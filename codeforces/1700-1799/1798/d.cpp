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
    cin >> n;
    multiset<int> neg, zero, pos;
    for(int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      if(x < 0)
        neg.ins(x);
      else if(x == 0)
        zero.ins(x);
      else
        pos.ins(x);
    }
    if(zero.size() == n) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    int cur = 0;
    for(int i = 1; i <= n; ++i) {
      if(neg.empty() && pos.empty()) {
        cout << 0 << " ";
      }
      else if(cur <= 0) {
        cur += *--pos.end();
        cout << *--pos.end() << " ";
        pos.erase(--pos.end());
      }
      else {
        cur += *neg.begin();
        cout << *neg.begin() << " ";
        neg.erase(neg.begin());
      }
    }
    cout << endl;
  }
  return 0;
}