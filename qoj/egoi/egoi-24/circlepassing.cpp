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

  auto dist = [&] (int x, int y) -> int {
    x %= 2 * n;
    y %= 2 * n;
    return min(abs(x - y), 2 * n - abs(x - y));
  };
  int a[3 * m];
  for (int i = 0; i < m; ++i) cin >> a[i];
  for (int i = m; i < 3 * m; ++i) a[i] = a[i - m] + n;
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    int res = 1e9;
    // no shortcut case
    res = min(res, dist(x, y));
    // cerr << "no shortcut " << res << endl;

    // find closest shortcuts that we can use
    vector<int> sc;
    int idx = lower_bound(a, a + 3 * m, x) - a;
    if (idx == 0) sc.push_back(0), sc.push_back(2 * m - 1);
    else sc.push_back(idx), sc.push_back(idx - 1);
    
    for (auto st : sc) {
      // x -> a[st] -> a[st] + n -> y
      res = min(res, dist(x, a[st]) + 1 + dist(a[st] + n, y));
    }

    cout << res << endl;
  }
  return 0;
}