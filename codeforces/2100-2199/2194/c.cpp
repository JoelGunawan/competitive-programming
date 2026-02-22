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
    int n, k;
    cin >> n >> k;
    // check all factors of n, is there a possible repetition?
    // there are a lot of possibilities, how to check? do a bitmask check, if there is a common one, then there is an intersection
    int mask[n + 5];
    memset(mask, 0, sizeof(mask));
    for (int i = 1; i <= k; ++i) {
      for (int j = 1; j <= n; ++j) {
        char c;
        cin >> c;
        int num = c - 'a';
        mask[j] |= 1 << num;
      }
    }

    // try all possible factors of n, check rep
    int max_rep = 0;
    string out = "";
    for (int rep = 1; rep <= n; ++rep) {
      if (n % rep) continue;

      int jump = n / rep;
      bool ans = 1;
      string res = "";
      for (int i = 1; i <= jump; ++i) {
        int cur_mask = INT_MAX;
        for (int j = i; j <= n; j += jump) {
          cur_mask &= mask[j];
        }
        if (!cur_mask) {
          ans = 0;
          break;
        } else {
          res += (char)('a' + __builtin_ctz(cur_mask));
        }
      }

      if (ans) {
        max_rep = rep;
        out = res;
      }
    }
    
    for (int i = 0; i < max_rep; ++i) {
      cout << out;
    }
    cout << endl;
  }
  return 0;
}