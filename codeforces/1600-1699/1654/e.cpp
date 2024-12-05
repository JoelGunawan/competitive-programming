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
  int n;
  cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  int blk = 325;
  int mx = 1;
  for(int i = 1; i <= n; ++i) {
    vector<int> v;
    for(int j = i + 1; j <= i + blk && j <= n; ++j) {
      int diff = (a[j] - a[i]) / (j - i);
      if(diff * (j - i) == a[j] - a[i]) {
        v.pb(diff);
        // cerr << i << " " << j << " " << diff << endl;
      }
    }
    sort(v.begin(), v.end());
    int adj = 0;
    for(int i = 0; i < v.size(); ++i) {
      if(i != 0 && v[i] != v[i - 1]) {
        mx = max(mx, adj + 1);
        adj = 0;
      }
      ++adj;
    }
    mx = max(mx, adj + 1);
  }
  for(int i = -blk; i <= blk; ++i) {
    vector<int> v;
    for(int j = 1; j <= n; ++j) {
      v.pb(a[j] - i * j);
    }
    sort(v.begin(), v.end());
    int adj = 0;
    for(int i = 0; i < v.size(); ++i) {
      if(i != 0 && v[i] != v[i - 1]) {
        mx = max(mx, adj);
        adj = 0;
      }
      ++adj;
    }
    mx = max(mx, adj);
  }
  cout << n - mx << endl;
  return 0;
}