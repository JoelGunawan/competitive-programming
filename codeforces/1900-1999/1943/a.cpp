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
    int cnt[n];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      ++cnt[x];
    }
    int fz = -1, fo = -1;
    for(int i = 0; i < n; ++i) {
      if(cnt[i] == 0) {
        fz = i;
        break;
      }
    }
    for(int i = 0; i < n; ++i) {
      if(cnt[i] == 1) {
        fo = i;
        break;
      }
    }
    if(fo == -1) {
      cout << fz << endl;
    }
    else if(fz == -1) {
      cout << 1 << endl;
    }
    else {
      int so = -1;
      for(int i = 0; i < n; ++i) {
        if(cnt[i] == 1 && i != fo) {
          so = i;
          break;
        }
      }
      if(so == -1) {
        cout << fz << endl;
      }
      else {
        cout << min(fz, so) << endl;
      }
    }
  }
  return 0;
}