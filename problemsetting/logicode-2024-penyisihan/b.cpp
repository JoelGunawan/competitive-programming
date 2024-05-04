// header file
#include <bits/stdc++.h>
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
int main() {
  //ios_base::sync_with_stdio(0); cin.tie(NULL);
  int k;
  cin >> k;
  vector<int> a[k + 1];
  for(int i = 1; i <= k; ++i) {
    int x;
    cin >> x;
    for(int j = 0; j < x; ++j) {
      int y;
      cin >> y;
      a[i].pb(y);
    }
    sort(a[i].begin(), a[i].end());
  }
  // min diff -> sorting
  // max diff -> find min that is not in cur
  int pre[k + 1], suf[k + 2];
  pre[0] = 1e9, suf[k + 1] = 1e9;
  suf[k] = a[k][0], pre[1] = a[1][0];
  for(int i = 2; i <= k; ++i)
    pre[i] = min(pre[i - 1], a[i][0]);
  for(int i = k - 1; i >= 1; --i)
    suf[i] = min(suf[i + 1], a[i][0]);
  int mx = 0;
  for(int i = 1; i <= k; ++i) {
    mx = max(mx, a[i].back() - min(pre[i - 1], suf[i + 1]));
  }
  multiset<int> cur;
  vector<pair<int, pair<int, int>>> v;
  for(int i = 1; i <= k; ++i) {
    for(int j = 1; j < a[i].size(); ++j) {
      v.pb(mp(a[i][j], mp(i, j)));
    }
    cur.ins(a[i][0]);
  }
  int mn = *--cur.end() - *cur.begin();
  sort(v.begin(), v.end());
  for(auto i : v) {
    cur.ins(i.fi);
    cur.erase(cur.find(a[i.se.fi][i.se.se - 1]));
    mn = min(mn, *--cur.end() - *cur.begin());
  }
  cout << mx << " " << mn << endl;
  return 0;
}