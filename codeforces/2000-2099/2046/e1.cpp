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
struct participant {
  int s, w, t, c;
  participant(int s, int w, int t) : s(s), w(w), t(t) {

  }
  participant() {
    s = -1, w = -1, t = -1, c = -1;
  }
};
void tc() {
  int n, m;
  cin >> n >> m;
  map<int, vector<int>> topic;
  map<int, bool> used_topic;
  participant a[n + 1];
  for(int i = 1; i <= n; ++i) {
    int s, w, t;
    cin >> s >> w >> t;
    a[i] = participant(s, w, t); 
    used_topic[t] = 1;
  }
  vector<int> c1, c2;
  for(int i = 1; i <= m; ++i) {
    int k;
    cin >> k;
    while(k--) {
      int x;
      cin >> x;
      if(i == 1)
        c1.pb(x);
      else
        c2.pb(x);
    }
  }
  // for each topic -> find maxS, maxW in city 2
  map<int, int> maxs, maxw;
  vector<pair<int, int>> v;
  for(auto x : c2)
    v.pb(mp(a[x].s, a[x].w));
  sort(v.begin(), v.end());
  // sort by strength, then by wisdom
  // for largest strength, maintain suffix max of wisdom
  int mns = 1e9;
  for(auto x : c1) {
    mns = min(mns, a[x].s);
  }
  int mxs = 0;
  for(auto x : c2) {
    mxs = max(mxs, a[x].s);
  }
  int mnw = 1e9;
  for(auto x : c1) {
    mnw = min(mnw, a[x].w);
  }
  if(mnw <= mxs) {
    // cerr << mnw << " " << mxs << endl;
    cout << -1 << endl;
    return;
  }
  for(auto x : c2) {
    maxs[a[x].t] = max(maxs[a[x].t], a[x].s);
    if(a[x].s >= mns)
      maxw[a[x].t] = max(maxw[a[x].t], a[x].w);
  }
  // not allowed ANYTHING between mns to mxs
  for(auto x : c1) {
    if(maxw[a[x].t] >= a[x].w) {
      if(a[x].s <= mxs) {
        // cerr << a[x].s << " " << maxw[a[x].t] << " " << a[x].w << mxs << endl;
        cout << -1 << endl;
        return;
      }
    }
    else if(a[x].s <= mxs) {
      if(a[x].w <= mxs) {
        // cerr << a[x].s << " " << a[x].w << " " << mxs << endl;
        cout << -1 << endl;
        return;
      }
    }
  } 
  vector<pair<int, int>> ops;
  int curt = 0;
  for(int i = 1; i <= 1; ++i) {
    while(used_topic[curt])
      ++curt;
    used_topic[curt] = 1;
    ops.pb(mp(mxs + 1, curt++));
  }
  for(int i = 1; i <= 1; ++i) {
    while(used_topic[curt]) 
      ++curt;
    used_topic[curt] = 1;
    ops.pb(mp(mns, curt++));
  }
  // for each topic in c1, such that the wisdom is greater than maxs, just choose that topic's max(maxs, maxw[a[x].t]) + 1
  for(auto x : c1)
    used_topic[a[x].t] = 0;
  for(auto x : c1) {
    if(!used_topic[a[x].t])
      ops.pb(mp(max(mxs, maxw[a[x].t]) + 1, a[x].t)), used_topic[a[x].t] = 1;
  }
  cout << ops.size() << endl;
  for(auto x : ops)
    cout << x.fi << " " << x.se << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}