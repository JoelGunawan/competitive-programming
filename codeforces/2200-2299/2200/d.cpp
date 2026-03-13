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
    int n, x, y;
    cin >> n >> x >> y;

    int p[n + 5];
    for (int i = 1; i <= n; ++i) {
      cin >> p[i];
    }

    // find first position of insertion that is optimal i.e. a[x + 1] < chosen
    vector<int> rst;
    for (int i = 1; i <= x; ++i) {
      rst.push_back(p[i]);
    }

    for (int i = y + 1; i <= n; ++i) {
      rst.push_back(p[i]);
    }

    vector<int> mid; 
    int mn_mid = 1e9;
    for (int i = x + 1; i <= y; ++i) {
      mid.push_back(p[i]);
      mn_mid = min(mn_mid, p[i]);
    }


    int idx = rst.size();
    for (int i = 0; i < rst.size(); ++i) {
      if (mn_mid < rst[i]) {
        idx = i;
        break;
      }
    }

    for (int i = 0; i < idx; ++i) {
      cout << rst[i] << " ";
    }

    int mid_idx = -1;
    for (int i = 0; i < mid.size(); ++i) {
      if (mid[i] == mn_mid) {
        mid_idx = i;
        break;
      }
    }

    for (int i = 0; i < mid.size(); ++i) {
      cout << mid[(mid_idx + i) % mid.size()] << " ";
    }

    for (int i = idx; i < rst.size(); ++i) {
      cout << rst[i] << " ";
    }
    
    cout << endl;
  }
  return 0;
}