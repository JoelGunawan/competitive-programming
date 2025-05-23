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
// o(nlogn), could be faster with hashmap but not necessary
void solve() {
  int n, x;
  cin >> n >> x;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  int idx = 1;
  map<int, int> cnt;
  for(int i = 0; i < n; ++i) {
    if(idx <= n && a[idx] <= i) {
      ++cnt[((a[idx] % x) + x) % x];
      ++idx;
    }
    if(cnt[i % x])
      --cnt[i % x];
    else {
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