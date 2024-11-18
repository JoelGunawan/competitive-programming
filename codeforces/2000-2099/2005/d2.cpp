#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int a[n + 5], b[n + 5];
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    for(int i = 1; i <= n; ++i)
      cin >> b[i];
    // observe that basically there are 3 phases
    // first phase: 
    // a take from a, b take from b
    // a take from b, b take from a
    // a take from a, b take from b
    // 0 -> 1 -> 2
    // valid: 1 -> 2, 0 -> 1 -> 2, 0 -> 1
    vector<map<pair<int, int>, ll>> dp(3);
    dp[0][mp(0, 0)] = 1;
    for(int i = 1; i <= n; ++i) {
      vector<map<pair<int, int>, ll>> nxt(3);
      for(int j = 0; j < 3; ++j) {
        for(auto p : dp[j]) {
          if(j == 0) {
            nxt[0][mp(gcd(p.fi.fi, a[i]), gcd(p.fi.se, b[i]))] += p.se;
            nxt[1][mp(gcd(p.fi.fi, b[i]), gcd(p.fi.se, a[i]))] += p.se;
          }
          else if(j == 1) {
            nxt[1][mp(gcd(p.fi.fi, b[i]), gcd(p.fi.se, a[i]))] += p.se;
            nxt[2][mp(gcd(p.fi.fi, a[i]), gcd(p.fi.se, b[i]))] += p.se;
          }
          else {
            nxt[2][mp(gcd(p.fi.fi, a[i]), gcd(p.fi.se, b[i]))] += p.se;
          }
        }
      }
      swap(nxt, dp);
    }
    int mx = 0; ll cnt = 0;
    for(int i = 1; i < 3; ++i) {
      for(auto p : dp[i]) {
        if(p.fi.fi + p.fi.se == mx)
          cnt += p.se;
        else if(p.fi.fi + p.fi.se > mx)
          cnt = p.se, mx = p.fi.fi + p.fi.se;
      }
    }
    cout << mx << " " << cnt << endl;
  }
  return 0;
}