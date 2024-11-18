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
    int rem = -1;
    for(int j = 0; j < v.size(); ++j) {
      if(v[j] <= i && ((v[j] % x) + x) % x == i % x) {
        rem = j;
        break;
      }
    } 
    if(rem == -1) {
      cout << i << endl;
      return;
    }
    else
      v.erase(v.begin() + rem);
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