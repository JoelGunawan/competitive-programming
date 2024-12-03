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
void tc() {
  int n;
  cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  int suff[n + 2];
  suff[n + 1] = 1e9;
  for(int i = n; i >= 1; --i)
    suff[i] = min(a[i], suff[i + 1]);
  multiset<int> move;
  // move.ins(1e9);
  vector<int> ans;
  for(int i = 1; i <= n; ++i) {
    // if(move.size())
    //   cerr << i << " " << (*move.begin()) << endl;
    if(suff[i] < a[i] || (move.size() && *move.begin() < a[i])) {
      // cerr << "HERE " << i << " " << suff[i] << " " << a[i] << " " << *move.begin() << endl;
      move.ins(a[i] + 1);
    }
    else
      ans.pb(a[i]);
  }
  for(auto x : move)
    ans.pb(x);
  for(auto x : ans)
    cout << x << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}