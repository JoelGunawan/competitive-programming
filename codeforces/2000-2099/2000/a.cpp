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
    string s;
    cin >> s;
    if(s.size() <= 2) {
      cout << "NO" << endl;
    }
    else {
      if(s.substr(0, 2) == "10") {
        // cout << "HERE" << endl;
        if(s[2] != '0' && (s[2] != '1' || s.size() == 4))
          cout << "YES" << endl;
        else 
          cout << "NO" << endl;
      }
      else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}