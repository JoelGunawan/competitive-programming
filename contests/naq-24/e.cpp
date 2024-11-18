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
  int cnt[51];
  memset(cnt, 0, sizeof(cnt));
  for(int i = 1; i <= 50 * n; ++i) {
    int x;
    cin >> x;
    ++cnt[x];
  }
  vector<int> ans;
  for(int i = 1; i <= 50; ++i) {
    if(cnt[i] > 2 * n)
      ans.pb(i);
  }
  if(ans.empty())
    cout << -1 << endl;
  else {
    for(auto x : ans) 
      cout << x << " ";
    cout << endl;
  }
  return 0;
}