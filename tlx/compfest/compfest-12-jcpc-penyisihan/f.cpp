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
  int n, m;
  cin >> n >> m;
  vector<int> v;
  for(int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    v.pb(x);
  }
  v.erase(find(v.begin(), v.end(), 0));
  ll cur = 1;
  ll sum = 0;
  vector<pair<int, int>> a;
  for(int i = 0; i < 20; ++i)
    cur = (cur * 10) % m;
  a.pb(mp(0, 20));
  // for(int i = 0; i < (int)v.size() - 1; ++i)
  //   a.pb(mp(v[i], 1)), sum = (sum + cur * v[i]) % m, cur = (cur * 10) % m;
  for(int i = 0; i < v.size(); ++i) {
    a.pb(mp(v[i], 0));
    do {
      ++a.back().se;
      sum = (sum + cur * v[i]) % m, cur = (cur * 10) % m;
    } while(sum != 0);
  }
  reverse(a.begin(), a.end());
  for(auto x : a)
    for(int j = 0; j < x.se; ++j)
      cout << x.fi; 
  cout << endl;
  return 0;
}