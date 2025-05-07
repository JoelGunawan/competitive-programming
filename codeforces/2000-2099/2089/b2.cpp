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
  ll n, k;
  cin >> n >> k;
  int a[n], b[n];
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  for(int i = 0; i < n; ++i)
    cin >> b[i];
  int ori[n];
  ll sum = 0, rem_sum = 0;
  for(int i = 0; i < n; ++i) {
    int x = min(a[i], b[i]);
    sum += a[i];
    a[i] -= x;
    b[i] -= x;
    rem_sum += a[i];
    ori[i] = i;
  }
  if(sum <= k) {
    cout << 0 << endl;
    return;
  }
  set<int> t;
  for(int i = 0; i < n; ++i) {
    if(a[i] > 0)
      t.insert(i);
  }
  if(t.empty()) {
    cout << 1 << endl;
    return;
  }
  // for each non-empty -> memo next "available" thing to reduce
  // sort by time
  set<int> s;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for(int i = 0; i < n; ++i) {
    if(b[i] > 0)
      s.insert(i);
  }
  for(int i = 0; i < n; ++i) {
    if(b[i] > 0) {
      int pr;
      if(*s.begin() == i) {
        pr = *--s.end();
        if(*t.begin() > i) {
          auto it = --t.end();
          if(pr == i || *it > pr) {
            pq.push({i + n - *it, *it});
          }
        }
        else {
          auto it = --t.lower_bound(i);
          pq.push({i - *it, *it});
        }
      }
      else {
        pr = *--s.lower_bound(i);
        auto it = t.begin();
        if((it = t.lower_bound(i)) != t.begin() && *--it > pr) {
          pq.push({i - *it, *it});
        }
      }
    }
  }
  if(k >= rem_sum) {
    cout << 1 << endl;
    return;
  }
  while(pq.size()) {
    auto [time, pos] = pq.top();
    pq.pop();
    int pos_b = pos + time;
    if(pos_b >= n)
      pos_b -= n;
    int tmp = min(a[pos], b[pos_b]);
    // cerr << pos << " " << pos_b << " " << tmp << " " << a[pos] << " " << b[pos_b] << " " << time << endl;
    a[pos] -= tmp;
    b[pos_b] -= tmp;
    rem_sum -= tmp;
    if(rem_sum <= k) {
      cout << time + 1 << endl;
      return;
    }
    if(a[pos] == 0) {
      // cerr << "ERASE " << pos << endl;
      t.erase(pos);
    }
    if(b[pos_b] == 0) {
      // allow next position to choose (if it doesn't have any, but we don't know so it's fine, we can just let it pick something new)
      s.erase(pos_b);
      if(*--s.end() < pos_b) {
        pos_b = *s.begin();
      }
      else {
        pos_b = *s.lower_bound(pos_b);
      }
      int pr;
      if(*s.begin() == pos_b) {
        pr = *--s.end();
        if(*t.begin() > pos_b) {
          auto it = --t.end();
          if(pr == pos_b || *it > pr) {
            pq.push({pos_b + n - *it, *it});
          }
        }
        else {
          auto it = --t.lower_bound(pos_b);
          pq.push({pos_b - *it, *it});
        }
      }
      else {
        pr = *--s.lower_bound(pos_b);
        auto it = t.begin();
        if((it = t.lower_bound(pos_b)) != t.begin() && *--it > pr) {
          pq.push({pos_b - *it, *it});
        }
      }
    }
    else {
      // choose something for current position (if exists)
      int pr;
      if(*s.begin() == pos_b) {
        pr = *--s.end();
        if(*t.begin() > pos_b) {
          auto it = --t.end();
          if(pr == pos_b || *it > pr) {
            pq.push({pos_b + n - *it, *it});
          }
        }
        else {
          auto it = --t.lower_bound(pos_b);
          pq.push({pos_b - *it, *it});
        }
      }
      else {
        pr = *--s.lower_bound(pos_b);
        auto it = t.begin();
        if((it = t.lower_bound(pos_b)) != t.begin() && *--it > pr) {
          pq.push({pos_b - *it, *it});
        }
      }
    }
  }
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