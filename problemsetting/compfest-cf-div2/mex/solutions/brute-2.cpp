#include <bits/stdc++.h>
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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
// O(n^2)
void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for(int i = 0; i < n; ++i)
    cin >> v[i];
  for(int i = 0; i < n; ++i) {
    vector<int> tmp;
    bool found = 0;
    while(v.size()) {
      if(v.back() <= i && ((v.back() % x) + x) % x == i % x) {
        v.pop_back();
        while(tmp.size())
          v.pb(tmp.back()), tmp.pop_back();
        found = 1;
        break;
      }
      else {
        tmp.pb(v.back()), v.pop_back();
      }
    }
    if(!found) {
      cout << i << endl;
      return;
    }
  }
  cout << n << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    solve();
  return 0;
}