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
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
struct block {
  int l = 1e9, r = 0;
  ll sum = 0;
  vector<int> vals;
  vector<int> sorted_prefix;
  int get_larger(int k) {
    return sorted_prefix.end() - upper_bound(sorted_prefix.begin(), sorted_prefix.end(), k);
  }
  int get_larger_prefix(int max_idx, int k) {
    ll cur = 0;
    int ret = 0;
    for(int i = l; i <= max_idx; ++i) {
      cur += vals[i - l];
      if(cur > k)
        ++ret; 
    }
    return ret;
  }
  // fi -> suffix
  // se -> ret
  pair<ll, int> get_larger_suffix(int first_idx, int k) {
    ll cur = 0;
    int ret = 0;
    for(int i = first_idx; i <= r; ++i) {
      cur += vals[i - l];
      if(cur > k)
        ++ret;
    }
    return mp(cur, ret);
  }
  void build() {
    sum = 0;
    sorted_prefix.clear();
    for(int i = 0; i < vals.size(); ++i) {
      sum += vals[i];
      sorted_prefix.pb(sum);
    }
    sort(sorted_prefix.begin(), sorted_prefix.end());
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  ll n, r, k;
  cin >> n >> r >> k;
  ll a[n + 1], b[n + 1], c[n + 1];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for(int i = 1; i <= n; ++i)
    cin >> b[i];
  for(int i = 1; i <= n; ++i)
    cin >> c[i];
  int sz = sqrt(n);
  ll prefa[n + 1], prefb[n + 1], prefc[n + 1], prefab[n + 1];
  prefa[0] = prefb[0] = prefc[0] = prefab[n + 1] = 0;
  for(int i = 1; i <= n; ++i) {
    prefa[i] = prefa[i - 1] + a[i];
    prefb[i] = prefb[i - 1] + b[i];
    prefc[i] = prefc[i - 1] + c[i];
    prefab[i] = prefab[i - 1] + b[i] - a[i];
  }
  if(r <= sz) {
    // do manually to avoid start/end in same block
    
  }
  else {
    // divide into blk
    // each blk -> sorted prefix sums
    // first/last blk -> manual
    vector<block> blks;
    int num[n + 1];
    for(int i = 1; i <= n; ++i) {
      if(i + r > n) {
        break;
      }
      num[i] = i / sz;
      while(num[i] + 1 < blks.size())
        blks.push_back(block());
      blks[num[i]].l = min(blks[num[i]].l, i);
      blks[num[i]].r = max(blks[num[i]].r, i);
      ll val = b[i] - c[i] + b[i + r] - a[i + r];
      blks[num[i]].vals.pb(val);
    }
    ll l = n, r = n * 1e6;
    while(l <= r) {
      int mid = (l + r) / 2;
      ll total = 0;
      // fully intersect
      for(int i = 1; i <= n; ++i) {
        // try prefix c
        if(i + r - 1 <= n) {
          if(prefa[i - 1] + prefa[n] - prefa[i + r - 1] + prefc[i + r - 1] - prefc[i - 1] >= mid)
            ++total;
        }
      }
      // zero intersect
      ordered_set pbds;
      for(int i = n; i >= 1; --i) {
        if(i + 2 * r - 1 <= n) {
          pbds.insert(mp(prefab[i + 2 * r - 1] - prefab[i + r - 1], i));
        }
        else {
          continue;
        }
        ll cur = prefab[i + r - 1] - prefab[i - 1];
        ll tot = prefa[n] + cur;
        // find values in pbds such that tot + x >= mid
        total += pbds.order_of_key(mp(mid - tot, 0));
      }
      if(r >= 2) {
        for(int i = 1; i <= n; ++i) {
          // from i to i + r - 2
          int l = i, r = min(n - r, i + r - 2); 
        }
      }
    }
  }
  return 0;
}