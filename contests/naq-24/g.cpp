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
  map<int, vector<int>> a;
  for(int i = 1; i <= n; ++i) {
    int s, c;
    cin >> s >> c;
    a[s].pb(c);
  }
  long double res = 0;
  // log(a * b) = log(a) + log(b)
  for(auto p : a) {
    vector<int> v = p.se;
    sort(v.begin(), v.end());
    int h = v.size() / 2;
    for(int i = 0; i < h; ++i) {
      res -= log(v[i]);
    }
    for(int i = v.size() - 1; i >= v.size() - h; --i) {
      res += log(v[i]);
    }
  }
  cout << fixed << setprecision(15);
  cout << res << endl;
  return 0;
}