#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// #define endl "\n"
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
bool query(int l, int r) {
  cout << "pantau " << l << " " << r << endl;
  string s;
  cin >> s;
  return s == "YA";
}
int main() {
  // ios_base::sync_with_stdio(0); cin.tie(NULL);
  string s;
  cin >> s;
  int pm, vm;
  cin >> pm >> vm;
  // init inputs dont matter for full sol actually :troll:
  // oh it matters for making every possibility naively
  vector<pair<int, pair<int, int>>> v;
  for(int i = 0; i <= pm; ++i)
    for(int j = 0; j <= vm; ++j)
      v.pb(mp(i, mp(i, j)));
  while(v.size() > 1) {
    sort(v.begin(), v.end());
    int ql = v[0].fi, qr = v[v.size() / 2 - 1].fi;
    bool ret = query(ql, qr);
    if(ret) {
      while(v.size() && v.back().fi > qr)
        v.pop_back();
    }
    else {
      reverse(v.begin(), v.end());
      while(v.size() && v.back().fi <= qr)
        v.pop_back();
    }
    for(auto &p : v)
      p.fi += p.se.se;
  }
  cout << "tembak " << v[0].fi << endl;
  return 0;
}