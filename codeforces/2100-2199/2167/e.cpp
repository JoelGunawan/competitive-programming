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
    int n, k, x;
    cin >> n >> k >> x;
    int a[n + 5];
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    int l = 1, r = x, ans = 0;
    while(l <= r) {
      int mid = (l + r) >> 1;
      set<pair<int, int>> ranges;
      ranges.emplace(x, 0);
      for (int i = 1; i <= n; ++i) {
        // delete [a[i] - mid, a[i] + mid]
        int cl = a[i] - mid, cr = a[i] + mid;
        auto it = ranges.lb(mp(cl, x + 5));
        while (it != ranges.end()) {
          auto [r, l] = *it;
          if (l >= cr)
            break;
          // cerr << "check " << l << " " << r << " " << cl << " " << cr << endl;
          ranges.erase(it);
          if (l <= cl) {
            // cerr << "create left" << endl;
            ranges.emplace(cl, l);
          }
          if (r >= cr) {
            // cerr << "create right" << endl;
            ranges.emplace(r, cr);
            break;
          }
          it = ranges.lb(mp(cl, x + 5));
        }
      }
      int tot = 0;
      for(auto [r, l] : ranges) {
        tot += r - l + 1;
      }
      // cerr << mid << " " << tot << " " << ranges.size() << endl;
      if (tot >= k)
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }

    if (ans == 0) {
      for(int i = 0; i < k; ++i) {
        cout << i << " ";
      }
      cout << endl;
    } else {
      set<pair<int, int>> ranges;
      ranges.emplace(x, 0);
      for (int i = 1; i <= n; ++i) {
        // delete [a[i] - ans, a[i] + ans]
        int cl = a[i] - ans, cr = a[i] + ans;
        auto it = ranges.lb(mp(cl, x + 5));
        while (it != ranges.end()) {
          auto [r, l] = *it;
          if (l >= cr)
            break;
          // cerr << "check " << l << " " << r << " " << cl << " " << cr << endl;
          ranges.erase(it);
          if (l <= cl) {
            // cerr << "create left" << endl;
            ranges.emplace(cl, l);
          }
          if (r >= cr) {
            // cerr << "create right" << endl;
            ranges.emplace(r, cr);
            break;
          }
          it = ranges.lb(mp(cl, x + 5));
        }
      }

      for (auto [r, l] : ranges) {
        for(int i = l; i <= r; ++i) {
          if(!k)
            break;
          --k;
          cout << i << " ";
        }
        if(!k)
          break;
      }
      cout << endl;
    }
  }
  return 0;
}