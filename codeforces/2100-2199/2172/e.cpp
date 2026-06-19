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
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<int> perm;
    for(auto c : s) {
      perm.push_back(c - '0');
    }
    vector<int> p2 = perm;
    int x, y;
    cin >> x >> y;
    for (int i = 1; i < x; ++i) {
      next_permutation(perm.begin(), perm.end());
    }
    for (int i = 1; i < y; ++i) {
      next_permutation(p2.begin(), p2.end());
    }
  
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (perm[i] == p2[i]) 
        ++res;
    }
    cout << res << "A" << s.size() - res << "B" << endl;
  }
  return 0;
}