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
  int a[n + 5];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  set<int> rem, del;
  int cnt[n + 5];
  memset(cnt, 0, sizeof(cnt));
  for(int i = 1; i <= n; ++i)
    rem.insert(a[i]), ++cnt[a[i]];
  int res = 0;
  for(int i = n; i >= 1; --i) {
    rem.erase(a[i]);
    del.insert(a[i]);
    --cnt[a[i]];
    if(rem.empty()) {
      ++res;
      for(auto x : del) {
        if(cnt[x])
          rem.insert(x);
      }
      del.clear();
    }
  }
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)  
    tc();
  return 0;
}