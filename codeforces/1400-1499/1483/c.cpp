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
  int n;
  cin >> n;
  int h[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> h[i];
  int b[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> b[i];
  // note that using stack algo, maintain the mins, along with the dp values
  // choose the best one we have
  ll dp[n + 1];
  dp[0] = 0;
  h[0] = 0;
  // fi -> idx, se -> dp value max
  vector<pair<int, ll>> st = {mp(0, 0)};
  multiset<ll> s;
  // takes beauty of building w/ minimum height
  for(int i = 1; i <= n; ++i) {
    // we actually need to process current index first
    ll pr = -1e18;
    // if current height is lower than previous ones, 
    // then we can "take over" the dp values that they maintain
    while(h[st.back().fi] > h[i]) {
      // we want to keep the pr max for the current one (maybe it might be best)
      pr = max(pr, st.back().se);
      // cerr << "DEL " << st.back().se + b[st.back().fi] << endl;
      s.erase(s.find(st.back().se + b[st.back().fi]));
      st.pop_back();
    }
    st.pb(mp(i, max(dp[i - 1], pr)));
    // cerr << "NEW " << st.back().se + b[st.back().fi] << endl;
    s.ins(st.back().se + b[st.back().fi]);
    dp[i] = *--s.end();
    // cerr << dp[i] << " ";
  }
  cout << dp[n] << endl;
  return 0;
}