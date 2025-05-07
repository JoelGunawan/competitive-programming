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
void tc() {
  int n, k;
  cin >> n >> k;
  int a[n + 1], b[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  for(int i = 1; i <= n; ++i)
    cin >> b[i];
  ll prefa[n + 1], prefb[n + 1];
  prefa[0] = prefb[0] = 0;
  for(int i = 1; i <= n; ++i)
    prefa[i] = prefa[i - 1] + a[i], prefb[i] = prefb[i - 1] + b[i];
  int pr[n + 1];
  memset(pr, -1, sizeof(pr));
  pr[1] = 0;
  for(int i = 2; i <= n; ++i) {
    int l = 0, r = i - 1, ans = -1;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(prefa[i] - min(prefa[mid], prefb[mid]) < k) {
        ans = mid;
        r = mid - 1;
      } 
      else
        l = mid + 1;
    }
    if(ans == -1) {
      cout << -1 << endl;
      return;
    }
    pr[i] = ans;
    // cout << "DEB " << i << " " << pr[i] << endl;
    if(prefb[i] - min(prefb[ans], prefa[ans]) >= k) {
      // have answer
      vector<int> v;
      int tmp = i;
      while(pr[tmp] != -1) {
        v.pb(pr[tmp]);
        tmp = pr[tmp];
      }
      v.pop_back(); // remove 0
      reverse(v.begin(), v.end());
      cout << v.size() << endl;
      for(auto x : v)
        cout << x << " ";
      cout << endl;
      return;
    }
  }
  cout << -1 << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}