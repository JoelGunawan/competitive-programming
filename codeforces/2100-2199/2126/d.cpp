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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a;
    for(int i = 0; i < n; ++i) {
      int l, r, ril;
      cin >> l >> r >> ril;
      a.emplace_back(ril, l);
    }
    sort(a.begin(), a.end());
    vector<pair<int, int>> v;
    
    for(int i = 0; i < n; ++i) {
      while(v.size() && v.back().se >= a[i].se)
        v.pop_back();
      v.push_back(a[i]);
    }
    
    int idx = lb(v.begin(), v.end(), mp(k, 0)) - v.begin();
    if(idx == v.size() || v[idx].se > k) {
      cout << k << endl;
      continue;
    }

    while(idx + 1 < v.size()) {
      if(v[idx + 1].se <= v[idx].fi) {
        ++idx;
      } else {
        break;
      }
    }

    cout << v[idx].fi << endl;
  }
  return 0;
}