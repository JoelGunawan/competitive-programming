#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  // insert at x, remove at y guaranteed exist
  vector<pair<int, int>> v[35];
  for(int i = 1; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    v[a].pb(mp(b, i));
  }
  set<pair<int, int>> s;
  int ans[n + 1];
  memset(ans, -1, sizeof(ans));
  for(int i = 1; i <= 31; ++i) {
    for(auto x : v[i])
      s.insert(x);
    for(int j = 0; j < k; ++j) {
      if(s.size() == 0)
        break;
      ans[(*s.begin()).se] = i;
      s.erase(s.begin());
    }
  }
  for(int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}