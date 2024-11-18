#include <bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define mp make_pair
#define ins insert
#define ll long long
#define endl "\n"
using namespace std;
const int lim = 3e6 + 5;
const int shift = lim / 2;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a[lim];
  int arr[n + 5];
  for(int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a[x + shift].pb(i);
    arr[i] = x + shift;
  }
  int res = 0;
  for(int i = 1; i < lim; ++i) {
    res = max(res, (int)a[i].size());
    if(k != 0 && i + k >= 0 && i + k < lim && a[i].size() && a[i + k].size()) {
      vector<int> v;
      for(auto x : a[i])
        v.pb(x);
      for(auto x : a[i + k])
        v.pb(x);
      sort(v.begin(), v.end());
      v.insert(v.begin(), 0);
      vector<int> suf(v.size() + 1);
      int n = v.size() - 1;
      suf[v.size()] = 0;
      int cnt = 0;
      for(int j = n; j >= 1; --j) {
        suf[j] = suf[j + 1];
        if(arr[v[j]] == i) {
          suf[j] = max(suf[j], suf[j + 1] + 1);
        }
        else
          ++cnt;
        suf[j] = max(suf[j], cnt);
      }
      res = max(res, suf[1]);
      cnt = 0;
      for(int j = 1; j <= n; ++j) {
        if(arr[v[j]] == i + k)
          ++cnt;
        // xcout << i << " " << j << " " << cnt << " " << suf[j + 1] << endl;
        res = max(res, cnt + suf[j + 1]);
      }
    }
  }
  cout << res << endl;
} 