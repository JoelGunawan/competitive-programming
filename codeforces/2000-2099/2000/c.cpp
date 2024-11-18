// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
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
    int a[n + 5];
    vector<vector<int>> v;
    vector<int> c;
    for(int i = 1; i <= n; ++i)
      cin >> a[i], c.pb(a[i]);
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    for(int i = 1; i <= n; ++i) {
      a[i] = lb(c.begin(), c.end(), a[i]) - c.begin();
    }
    v = vector<vector<int>>(c.size());
    for(int i = 1; i <= n; ++i)
      v[a[i]].pb(i);
    bool all_ans = v.size() <= 26;
    int m;
    cin >> m;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    // for(auto x : v) {
    //   for(auto y : x) {
    //     cout << y << " ";
    //   }
    //   cout << endl;
    // }
    while(m--) {
      vector<int> pos[26];
      string s;
      cin >> s;
      for(int i = 0; i < s.size(); ++i) {
        pos[s[i] - 'a'].pb(i + 1);
      }
      sort(pos, pos + 26);
      reverse(pos, pos + 26);
      // for(int i = 0; i < 26; ++i) {
      //   if(pos[i].size() == 0)
      //     break;
      //   for(auto x : pos[i]) {
      //     cout << x << " ";
      //   }
      //   cout << endl;
      // }
      bool ans = 1;
      for(int i = 0; i < 26; ++i) {
        if((pos[i].size() > 0 && v.size() <= i) || (pos[i].size() != 0 && pos[i] != v[i])) {
          // if(v.size() > i) {
          //   cout << "DEBUG " << i << endl;
          //   for(auto x : v[i]) {
          //     cout << x << " ";
          //   }
          //   cout << endl;
          //   for(auto x : pos[i]) {
          //     cout << x << " ";
          //   }
          //   cout << endl;
          // }
          // else {
          //   cout << pos[i].size() << " " << v.size() << endl;
          // }
          ans = 0;
          break;
        }
      }
      cout << ((ans && all_ans) ? "YES" : "NO") << endl;
    }
  }
  return 0;
}