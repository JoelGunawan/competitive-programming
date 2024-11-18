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
  int n, m, q;
  cin >> n >> m >> q;
  int a[n + 1][m + 1];
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j)
      cin >> a[i][j];
  }
  int res = 0;
  int mxr[n + 1], mxc[m + 1];
  pair<int, int> idxr[n + 1], idxc[m + 1];
  memset(mxr, 0, sizeof(mxr)), memset(mxc, 0, sizeof(mxc));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(a[i][j] > mxc[j])
        mxc[j] = a[i][j], idxc[j] = mp(i, j);
      if(a[i][j] > mxr[i])
        mxr[i] = a[i][j], idxr[i] = mp(i, j);
    }
  }
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      if(mxc[j] == a[i][j] && mxr[i] == a[i][j])
        ++res;
  while(q--) {
    int r, c, x;
    cin >> r >> c >> x;
    // check row and column
    if(mxr[r] == a[r][c] && mxc[c] == a[r][c])
      --res;
    a[r][c] = x;
    if(x > mxr[r]) {
      // update row
      pair<int, int> cur = idxr[r];
      if(cur != mp(r, c)) {
        if(mxr[cur.fi] == a[cur.fi][cur.se] && mxc[cur.se] == a[cur.fi][cur.se])
          --res;
      }
      idxr[r] = mp(r, c);
      mxr[r] = x;
    }
    if(x > mxc[c]) {
      pair<int, int> cur = idxc[c];
      if(cur != mp(r, c)) {
        if(mxr[cur.fi] == a[cur.fi][cur.se] && mxc[cur.se] == a[cur.fi][cur.se])
          --res;
      }
      idxc[c] = mp(r, c);
      mxc[c] = x;
    }
    if(mxr[r] == a[r][c] && mxc[c] == a[r][c])
      ++res;
    cout << res << endl;
  }
  return 0;
}