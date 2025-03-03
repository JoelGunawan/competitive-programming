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
  int n;
  cin >> n;
  int res = 0;
  for(int i = 1; i <= min(n, 100); ++i) {
    string s = to_string(i);
    vector<int> a;
    int sum = 0, mul = 1;
    for(int j = 0; j < s.size(); ++j) {
      sum += s[j] - '0';
      mul *= s[j] - '0';
    }
    if(sum + mul == i) 
      ++res;
  }
  cout << res << endl;
  return 0;
}