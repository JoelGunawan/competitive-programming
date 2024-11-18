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
  // just do dp with small technique for updating concurrently
  // sqrt decomp
  int n;
  cin >> n;
  pair<int, int> a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i].fi >> a[i].se;
  int blk = sqrt(n);
  int cnt[blk + 1][blk + 1];
  memset(cnt, 0, sizeof(cnt));
  // for cnt
  vector<pair<int, int>> reduce[n + 1];
  vector<pair<int, int>> add[n + 1];
  vector<int> transition[n + 1];
  for(int i = 1; i <= n; ++i) {
    if(a[i].fi <= blk) {
      ++cnt[a[i].fi][i % a[i].fi];
    }
  }
  return 0;
}