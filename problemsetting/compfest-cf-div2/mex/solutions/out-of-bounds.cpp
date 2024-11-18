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
using namespace std;
// forgot to stop
void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for(int i = 0; i < n; ++i)
    cin >> v[i];
  sort(v.begin(), v.end(), greater<int>());
  unordered_map<int, int> cnt;
  for(int i = 0; i < 2 * n; ++i) {
    // out of bounds here if don't stop at n
    while(v.back() <= i) {
      ++cnt[(((v.back()) % x) + x) % x];
      v.pop_back();
    }
    if(cnt[i % x] == 0) {
      cout << i << endl;
      return;
    }
    else
      --cnt[i % x];
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