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
  int p, n;
  cin >> p >> n;
  vector<int> edges[n + 1];
  for(int i = 1; i <= n; ++i) {
    int k;
    cin >> k;
    while(k--) {
      int x;
      cin >> x;
      edges[i].pb(x);
    }
    sort(edges[i].begin(), edges[i].end());
  }
  if(p == 1) {
    int wrong[n + 1];
    memset(wrong, 0, sizeof(wrong));
    for(int i = 1; i <= n; ++i) {
      for(auto x : edges[i]) {
        if(!binary_search(edges[x].begin(), edges[x].end(), i))
          ++wrong[i], ++wrong[x];
      }
    }
    for(int i = 1; i <= n; ++i)
      if(wrong[i] > 1) {
        cout << i << endl;
        return 0;
      }
  }
  else {
    // need to choose 2 nodes where it will cover all wrong
    // how to check if 2 nodes are all wrong, guaranteed only 1 thing
    int wrong[n + 1];
    memset(wrong, 0, sizeof(wrong));
    vector<int> adj[n + 1];
    set<pair<int, int>> s;
    for(int i = 1; i <= n; ++i) {
      for(auto x : edges[i]) {
        if(!binary_search(edges[x].begin(), edges[x].end(), i))
          ++wrong[i], ++wrong[x], adj[i].pb(x), adj[x].pb(i), s.insert(mp(min(i, x), max(i, x)));
      }
    }
    int ref = -1;
    for(int i = 1; i <= n; ++i) {
      if(wrong[i] > 2)
        ref = i;
    }
    vector<int> ans;
    if(ref == -1) {
      // try all combinations, not a lot (at most 4 nodes wrong)
      // cerr << "HERE" << endl;
      vector<int> possible;
      for(int i = 1; i <= n; ++i)
        if(wrong[i])
          possible.push_back(i);
      set<pair<int, int>> tmp(s);
      for(int i = 0; i < possible.size(); ++i)
        for(int j = i + 1; j < possible.size(); ++j) {
          int cura = possible[i], curb = possible[j];
          // cerr << i << " " << j << " " << possible.size() << endl;
          // cerr << cura << " " << curb << endl;
          for(auto x : adj[cura])
            if(s.find(mp(min(cura, x), max(cura, x))) != s.end())
              s.erase(s.find(mp(min(cura, x), max(cura, x))));
          for(auto x : adj[curb])
            if(s.find(mp(min(curb, x), max(curb, x))) != s.end())
              s.erase(s.find(mp(min(curb, x), max(curb, x))));
          if(s.size() == 0) {
            ans.pb(cura), ans.pb(curb);
          }
          s = tmp;
        }
    }
    else {;
      for(auto x : adj[ref])
        s.erase(s.find(mp(min(ref, x), max(ref, x))));
      for(int i = 1; i <= n; ++i) {
        if(i == ref)
          continue;
        for(auto x : adj[i]) {
          if(x != ref)
            s.erase(s.find(mp(min(i, x), max(i, x))));
        }
        if(s.size() == 0) {
          ans.pb(ref);
          ans.pb(i);
          break;
        }
        for(auto x : adj[i]) {
          if(x != ref)
            s.insert(mp(min(i, x), max(i, x)));
        }
      }
    }
    sort(ans.begin(), ans.end());
    for(auto x : ans)
      cout << x << " ";
    cout << endl;
  }
  return 0;
}