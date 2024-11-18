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
const int lim = 1 << 12;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
void tc() {
  int n, k, q;
  cin >> n >> k >> q;
  int a[n + 5];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = i - a[i];
  }
  multiset<int> freq;
  for(int i = 1; i <= n; ++i) 
    freq.ins(0);
  gp_hash_table<int, int, chash> cnt;
  for(int i = 1; i <= k; ++i) {
    freq.erase(freq.find(cnt[a[i]]));
    ++cnt[a[i]];
    freq.ins(cnt[a[i]]);
  }
  int res[n + 5];
  for(int i = k; i <= n; ++i) {
    res[i - k + 1] = k - *--freq.end();
    if(i != n) {
      freq.erase(freq.find(cnt[a[i + 1]]));
      ++cnt[a[i + 1]];
      freq.ins(cnt[a[i + 1]]);
    }
    freq.erase(freq.find(cnt[a[i - k + 1]]));
    --cnt[a[i - k + 1]];
    freq.ins(cnt[a[i - k + 1]]);
  }
  freq.clear();
  while(q--) {
    int l, r;
    cin >> l >> r;
    cout << res[l] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}