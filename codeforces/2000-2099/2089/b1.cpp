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
const int lim = 2e5 + 5;
void tc() {
  int n, k;
  cin >> n >> k;
  int a[n], b[n];
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  for(int i = 0; i < n; ++i)
    cin >> b[i];
  int ori[n];
  ll sum = 0;
  for(int i = 0; i < n; ++i) {
    int x = min(a[i], b[i]);
    sum += a[i];
    a[i] -= x;
    b[i] -= x;
    ori[i] = i;
  }
  if(sum <= k) {
    cout << 0 << endl;
    return;
  }
  // maintain non-zero b positions, use set
  set<int> s;
  for(int i = 0; i < n; ++i) {
    if(b[i] > 0)
      s.insert(i);
  }
  set<int> t;
  for(int i = 0; i < n; ++i) {
    if(a[i] > 0)
      t.insert(i);
  }
  // cerr << "TEST" << endl;
  if(t.empty()) {
    cout << 1 << endl;
    return;
  }
  int cur = *t.begin();
  t.erase(t.begin());
  while(t.size() || a[cur] > 0) {
    // find next empty, if conflict, then insert to t and change cur to --upper_bound of next pos
    auto it = s.begin();
    if(a[cur] == 0) {
      cur = *t.begin();
      t.erase(t.begin());
    }
    // cerr << cur << " " << a[cur] << endl;
    if((it = s.lower_bound(cur)) == s.end()) {
      int nx_pos = *s.begin();
      if(t.size() > 0 && (*--t.end() > cur || *t.begin() < nx_pos)) {
        t.insert(cur);
        if(*t.begin() < nx_pos) {
          auto it = t.upper_bound(nx_pos);
          --it;
          cur = *it;
          t.erase(it);
        }
        else {
          cur = *--t.end();
          t.erase(--t.end());
        }
      }
      else {
        // cerr << "RED " << ori[cur] << " " << nx_pos << endl;
        a[nx_pos] = a[cur];
        a[cur] = 0;
        ori[nx_pos] = ori[cur];
        int tmp = min(a[nx_pos], b[nx_pos]);
        a[nx_pos] -= tmp;
        b[nx_pos] -= tmp;
        cur = nx_pos;
        if(b[nx_pos] == 0)
          s.erase(nx_pos);
      }
    }
    else {
      int nx_pos = *it;
      auto it = t.begin();
      if((it = t.lower_bound(cur)) == t.end() || *it > nx_pos) {
        // cerr << "RED " << ori[cur] << " " << nx_pos << endl;
        a[nx_pos] = a[cur];
        a[cur] = 0;
        ori[nx_pos] = ori[cur];
        int tmp = min(a[nx_pos], b[nx_pos]);
        a[nx_pos] -= tmp;
        b[nx_pos] -= tmp;
        cur = nx_pos;
        if(b[nx_pos] == 0)
          s.erase(nx_pos);
      }
      else {
        t.insert(cur);
        auto it = t.upper_bound(nx_pos);
        --it;
        cur = *it;
        t.erase(it);
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    if(ori[i] <= i)
      ans = max(ans, i - ori[i]);
    else
      ans = max(ans, n + i - ori[i]);
  }
  cout << ans + 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    tc();
  }
  return 0;
}