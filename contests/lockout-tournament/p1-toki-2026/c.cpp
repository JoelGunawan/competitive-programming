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
  while (t--) {
    int n;
    cin >> n;
    int h[n + 5][n + 5];
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        cin >> h[i][j];
      }
    }

    int a[n + 5], b[n + 5];
    for (int i = 1; i <= n; ++i)
      cin >> a[i];

    for (int i = 1; i <= n; ++i)
      cin >> b[i];

    bool rc[n + 5], rr[n + 5];
    memset(rc, 0, sizeof(rc));
    memset(rr, 0, sizeof(rr));

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i > 1 && h[i][j] == h[i - 1][j]) {
          rr[i - 1] = 1;
        }
        
        if (j > 1 && h[i][j] == h[i][j - 1]) {
          rc[j - 1] = 1;
        }
      }
    }

    ll dpr[n + 5], dpc[n + 5];
    memset(dpr, 0, sizeof(dpr));
    memset(dpc, 0, sizeof(dpc));

    for (int i = 1; i <= n; ++i) {
      if (rr[i]) {
        dpr[i] = dpr[i - 2] + a[i];
      } else if (rr[i - 1]) {
        dpr[i] = min(dpr[i - 1], dpr[i - 2] + a[i]);
      } else {
        dpr[i] = dpr[i - 1];
      }
    }

    for (int i = 1; i <= n; ++i) {
      if (rc[i]) {
        dpc[i] = dpc[i - 2] + b[i];
      } else if (rc[i - 1]) {
        dpc[i] = min(dpc[i - 1], dpc[i - 2] + b[i]);
      } else {
        dpc[i] = dpc[i - 1];
      }
    }

    cout << dpr[n] + dpc[n] << endl;
  }
  return 0;
}