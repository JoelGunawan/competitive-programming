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
bool valid(int x, int y) {
  //cout << x << " " << y << " " << (((x + y) * (x + y) - x - y) % 3 == 0) << endl;
  return (2 * x * y + 2 * y * (y - 1) + 2 * x * (x - 1)) % 3 == 0;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  int cnt[3][3];
  memset(cnt, 0, sizeof(cnt));
  ++cnt[0][0];
  int cnt1 = 0, cnt2 = 0;
  ll res = 0;
  for(int idx = 1; idx <= n; ++idx) {
    int x;
    cin >> x;
    if(x % 3 == 1)
      ++cnt1, cnt1 %= 3;
    else if(x % 3 == 2)
      ++cnt2, cnt2 %= 3;
    for(int i = 0; i < 3; ++i) {
      for(int j = 0; j < 3; ++j) {
        if(valid(cnt1 - i, cnt2 - j)) {
          res += cnt[i][j];
        }
      }
    }
    ++cnt[cnt1][cnt2];
  }
  cout << res << endl;
  return 0;
}