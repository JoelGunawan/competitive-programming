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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  char a[n + 1][m + 1];
  memset(a, 0, sizeof(a));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  } 
  int hor[n + 2][m + 2], ver[n + 2][m + 2];
  memset(hor, 0, sizeof(hor));
  memset(ver, 0, sizeof(ver));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      hor[i][j] = a[i][j] == '-' ? hor[i][j - 1] + 1 : 0;
      ver[i][j] = a[i][j] == '|' ? ver[i - 1][j] + 1 : 0;
      // cout << hor[i][j] << " ";
    }
    // cout << endl;
  }
  map<pair<int, int>, vector<int>> verp, horp;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(hor[i][j] > hor[i][j + 1])
        horp[mp(j - hor[i][j] + 1, j)].pb(i);
      if(ver[i][j] > ver[i + 1][j])
        verp[mp(i - ver[i][j] + 1, i)].pb(j);
    }
  }
  ll res = 0;
  for(auto p : verp) {
    vector<int> arr = p.se;
    sort(arr.begin(), arr.end());
    int l = p.fi.fi, r = p.fi.se;
    int idx = -1;
    ll cur = 0;
    for(int i = 0; i < arr.size(); ++i) {
      if(idx < i)
         ++idx, cur += arr[idx];
      if(i != 0)
        cur -= arr[i - 1];
      // cout << l << " " << r << " " << arr[i] << endl;
      // if(idx + 1 < arr.size())
      //   cout << "CHECK " << arr[idx + 1] << " " << l - 1 << " " << r + 1 << endl;
      while(idx + 1 < arr.size() && hor[l - 1][arr[idx + 1]] >= arr[idx + 1] - arr[i] && hor[r + 1][arr[idx + 1]] >= arr[idx + 1] - arr[i]) {
        ++idx, cur += arr[idx];
      }
      // cout << cur << " " << i << " " << idx << " " << arr[i] << endl;
      res += (cur - 1ll * (idx - i + 1) * arr[i] - (idx - i)) * (r - l + 1);
    }
  }
  for(auto p : horp) {
    vector<int> arr = p.se;
    sort(arr.begin(), arr.end());
    int l = p.fi.fi, r = p.fi.se;
    int idx = -1;
    ll cur = 0;
    for(int i = 0; i < arr.size(); ++i) {
      if(idx < i)
         ++idx, cur += arr[idx];
      if(i != 0)
        cur -= arr[i - 1];
      // cout << l << " " << r << " " << arr[i] << endl;
      // if(idx + 1 < arr.size())
      //   cout << "CHECK " << arr[idx + 1] << " " << l - 1 << " " << r + 1 << endl;
      while(idx + 1 < arr.size() && ver[arr[idx + 1]][l - 1] >= arr[idx + 1] - arr[i] && ver[arr[idx + 1]][r + 1] >= arr[idx + 1] - arr[i]) {
        ++idx, cur += arr[idx];
      }
      // res += idx - i;
      res += (cur - 1ll * (idx - i + 1) * arr[i] - (idx - i)) * (r - l + 1);
    }
  }
  cout << res << endl;
  return 0;
}