#include <bits/stdc++.h>
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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  string buang;
  cin >> buang;
  int n;
  cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
      cin >> a[i];
  bool exists[n + 1];
  memset(exists, 0, sizeof(exists));
  int r = 0;
  int mx[n + 1], mx2[n + 1];
  for(int i = 1; i <= n; ++i) {
    while(r + 1 <= n && !exists[a[r + 1]])
      exists[a[++r]] = 1;
    mx[i] = r - i + 1;
    exists[a[i]] = 0;
  }
  int l = n + 1;
  for(int i = n; i >= 1; --i) {
    while(l - 1 >= 1 && !exists[a[l - 1]])
      exists[a[--l]] = 1;
    mx2[i] = i - l + 1;
    exists[a[i]] = 0;
  }
  pair<int, int> res = mp(0, 0);
  int pr = mx2[1];
  for(int i = 2; i <= n; ++i) {
    res = max(res, mp(min(mx[i], pr), i));
    pr = max(pr, mx2[i]);
  }
  for(int i = 1; i < res.se; ++i) {
    if(mx2[i] >= res.fi) {
      cout << i - res.fi + 1 << " " << i << " " << res.se << " " << res.se + res.fi - 1 << endl;
      return 0;
    }
  }
  return 0;
}