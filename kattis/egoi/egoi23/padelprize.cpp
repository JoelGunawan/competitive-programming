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

const int lim = 2e5 + 5;
struct disjoint_set {
  int h[lim], sz[lim];
  disjoint_set() {
    memset(h, -1, sizeof(h));
    fill(sz, sz + lim, 1);
  }
  int fh(int nd) {
    return h[nd] == -1 ? nd : fh(h[nd]);
  }
  bool merge(int x, int y) {
    x = fh(x), y = fh(y);
    if(x != y) {
      if(sz[x] < sz[y])
        swap(x, y);
      sz[x] += sz[y];
      h[y] = x;
    }
    return x != y;
  }
};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  pair<int, int> a[m];
  for(int i = 0; i < m; ++i)
    cin >> a[i].fi >> a[i].se;
  disjoint_set dsu;
  
  
  return 0;
}