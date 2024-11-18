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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n, q;
    cin >> n >> q;
    int a[n + 5];
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    // q doesn't matter because we count for all
    vector<int> s;
    for(int i = 0; i < n; ++i)
      s.pb(a[i + 1]);
    sort(s.begin(), s.end());
    int lim = min(n, max(500, (int)sqrt(n)));
    int res[n + 1]; 
    for(int i = 1; i <= lim; ++i) {
      // just do this manually, modulo each array and check the median using sorting
      int cnt[i + 1];
      memset(cnt, 0, sizeof(cnt));
      for(int j = 1; j <= n; ++j) {
        ++cnt[a[j] % i];
      }
      int cur = 0;  
      for(int j = 0; j <= i; ++j) {
        cur += cnt[j];
        // cout << "DEBUG2 " << i << " " << j << " " << cur << endl;
        if(cur > n / 2) {
          res[i] = j;
          break;
        }
      }
    }
    // for each block, determine whether we should move to left/right
    vector<int> sep = {n - 1};
    for(int i = n; i > lim; --i) {
      for(int j = 0; j < sep.size(); ++j) {
        while(sep[j] > 0 && s[sep[j]] - 1ll * j * i >= i)
          --sep[j];
      }
      if(sep.back() != n - 1)
        sep.pb(n - 1);
      // cout << "DEBUG SEP " << i << endl;
      // for(auto x : sep)
      //   cout << x << " ";
      // cout << endl;
      // sep should be correct
      // now process what the median is, finding in each block what is the required
      int l = 0, r = i - 1, ans = r;
      while(l <= r) {
        int mid = (l + r) / 2;
        int cur = 0;
        // cout << "DEBUG " << i << " " << mid << endl;
        for(int j = 0; j < sep.size(); ++j) {
          // cout << "LEFT " << (j == 0 ? -1 : sep[j - 1]) + 1 << " RIGHT " << sep[j] << " FIND " << j * i + mid << endl;
          // int old_cur = cur;
          cur += ub(s.begin() + (j == 0 ? -1 : sep[j - 1]) + 1, s.begin() + sep[j] + 1, 1ll * j * i + mid) - (s.begin() + (j == 0 ? -1 : sep[j - 1]) + 1);
          // cout << "ADD " << cur - old_cur << endl;
        }
        if(cur > n / 2) {
          r = mid - 1; ans = mid;
        }
        else {
          l = mid + 1;
        }
      }
      res[i] = ans;
    }
    // cout << "OUTPUT RES" << endl;
    // for(int i = 1; i <= n; ++i) {
    //   cout << res[i] << " ";
    // }
    // cout << endl;
    while(q--) {
      int x;
      cin >> x;
      cout << res[x] << " ";
    }
    cout << endl;
  }
  return 0;
}