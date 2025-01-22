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
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
      cin >> a[i].fi;
    bool par = 0;
    for(int i = 0; i < n; ++i) {
      cin >> a[i].se;
      if(a[i].se < a[i].fi)
        swap(a[i].fi, a[i].se), par ^= 1;
    }
    sort(a, a + n);
    bool ans = 1;
    int rev = 0;
    for(int i = 1; i < n; ++i) {
      if(a[i - 1].se > a[i].se) {
        ans = 0;
      }
      // reverse everything in remaining, first i or last n - i
      else if(a[i - 1].se < a[i].fi && (i & 1))
        ++rev;
    }
    if(ans && (rev >= 1 || (n & 1) || !par))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}