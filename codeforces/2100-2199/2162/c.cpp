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
  while(t--) {
    int a, b;
    cin >> a >> b;
    int msba = 0, msbb = 0;
    for(int i = 0; i < 31; ++i) {
      if(a < (1 << i)) {
        msba = i - 1;
        break;
      }
    }

    for(int i = 0; i < 31; ++i) {
      if(b < (1 << i)) {
        msbb = i - 1;
        break;
      }
    }

    if(msba < msbb) {
      cout << -1 << endl;
      continue;
    }

    cout << 2 << endl;
    int tgt = (1 << msba) - 1;
    int after = (1 << (msba + 1)) - 1;
    cout << ((a - (1 << msba)) ^ tgt) << " " << (after ^ b) << endl;
  }
  return 0;
}