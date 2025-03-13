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
  string a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  string t;
  cin >> t;
  vector<char> res[t.size()];
  for(int i = 1; i <= n; ++i) {
    int idxa = 0, idxt = 0;
    while(idxa < a[i].size()) {
      while(idxa < a[i].size() && a[i][idxa] != t[idxt]) {
        res[idxt].push_back(a[i][idxa]);
        ++idxa;
      }
      if(idxa < a[i].size()) {
        ++idxa; ++idxt;
      }
      if(idxt == t.size()) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  string out = "";
  for(int i = 0; i < t.size(); ++i) {
    for(auto j : res[i])
      out += j;
    out += t[i];
  }
  out.pop_back();
  cout << "YES" << endl << out << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  while(t--) {
    tc();
  }
  return 0;
}