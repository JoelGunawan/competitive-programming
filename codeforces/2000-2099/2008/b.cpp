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
    string s;
    cin >> s;
    // square beautiful matrix -> just check sqrt(n)
    int x = sqrt(n);
    if(x * x != n) {
      cout << "No" << endl;
      continue;
    }
    bool ans = 1;
    for(int i = 0; i < x; ++i) {
      if(s[i] == '0')
        ans = 0;
    }
    for(int i = 1; i < x - 1; ++i) { 
      if(s[i * x] == '0')
        ans = 0;
      for(int j = 1; j < x - 1; ++j) {
        if(s[i * x + j] == '1')
          ans = 0;
      }
      if(s[i * x + x - 1] == '0')
        ans = 0;
    }
    for(int i = n - x; i < n; ++i) {
      if(s[i] == '0')
        ans = 0;
    }
    cout << (ans ? "Yes" : "No") << endl;
  }
  return 0;
}