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
  ll n, d, x;
  cin >> n >> d >> x;
  int k[n + 1], c[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> k[i];
  for(int i = 1; i <= n; ++i)
    cin >> c[i];
  int diff[n + 1];
  memset(diff, 0, sizeof(diff));
  pair<int, ll> a[n + 1];
  for(int i = 1; i <= n; ++i)
    a[i] = mp(c[i], k[i]);
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  ll cnt = 1ll * x * d;
  ll res = 0;
  for(int i = 1; i <= n; ++i) {
    res += min({a[i].se, d, cnt}) * a[i].fi;
    cnt -= min({a[i].se, d, cnt});
  }
  cout << res << endl;
  return 0;
}