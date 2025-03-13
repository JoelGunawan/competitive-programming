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
  int n, k;
  cin >> n >> k;
  multiset<int> s;
  for(int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    s.ins(x);
  }
  int res = 0;
  while(s.size()) {
    // pair s.begin() with something such that the sum is < k
    if(*s.begin() >= k) {
      s.erase(s.begin()), ++res;
      continue;
    }
    int cur = *s.begin();
    s.erase(s.begin());
    if(s.empty()) {
      ++res;
      break;
    }
    // find < k - cur
    if(s.lb(k - cur) == s.begin()) {
      // dne, just make of size 2
      s.erase(--s.end());
    }
    else {
      s.erase(--s.lb(k - cur));
      if(s.size()) {
        s.erase(--s.end());
      }
    }
    ++res;
  }
  cout << res - 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}