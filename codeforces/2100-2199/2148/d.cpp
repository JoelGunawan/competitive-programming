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
    int n;
    cin >> n;
    int a[n + 5];
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    vector<int> even, odd;
    for(int i = 1; i <= n; ++i) {
      if(a[i] & 1)
        odd.push_back(a[i]);
      else
        even.push_back(a[i]);
    }
    
    if(odd.empty()) {
      cout << 0 << endl;
    } else {
      ll res = 0;
      for(auto x : even)
        res += x;
      sort(odd.begin(), odd.end(), greater<int>());
      int half = (odd.size() >> 1) + (odd.size() & 1);
      for(int i = 0; i < half; ++i) {
        res += odd[i];
      }
      cout << res << endl;
    }
  }
  return 0;
}