#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
int mid;
bool compare(pair<int, int> a, pair<int, int> b) {
  return 1ll * a.fi * mid - a.se < 1ll * b.fi * mid - b.se;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  pair<int, int> a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i].fi;
  for(int i = 1; i <= n; ++i)
    cin >> a[i].se;
  // for each friend, calculate which one is more optimal
  // kentang utuh less -> use kentang utuh
  // kentang utuh more -> use potongan
  int l = 1, r = 1e9, ans;
  while(l <= r) {
    mid = (l + r) / 2;
    // more optimal to use potongan
    sort(a + 1, a + n + 1, compare);
    ll utuh = k, potong = 0;
    for(int i = 1; i <= n; ++i) {
      if((a[i].se - potong) <= 1ll * mid * a[i].fi) {
        int req = ceil((a[i].se - potong) / (double)mid);
        req = max(req, 0);
        potong += 1ll * req * mid;
        utuh -= req;
        potong -= a[i].se;
      }
      else {
        utuh -= a[i].fi;
      }
    }
    // cout << utuh << " " << potong << endl;
    if(utuh < 0) 
      l = mid + 1;
    else
      r = mid - 1, ans = mid;
  } 
  cout << ans << endl;
  return 0;
}