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
    int a[n + 1], b[n + 1];
    for(int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    for(int i = 1; i <= n; ++i) {
      cin >> b[i];
    }
    // if two in a row (in b), delete and insert anywhere to the left
    int idx = n;
    map<int, int> cnt;
    bool ans = 1;
    for(int i = n; i >= 1; --i) {
      if(a[i] == b[idx]) {
        --idx;
        continue;
      }
      //cout << i << endl;
      while(idx != n && a[i] != b[idx] && b[idx] == b[idx + 1]) {
        ++cnt[b[idx]];
        --idx;
      }
      if(a[i] == b[idx]) {
        --idx;
        continue;
      }
      if(cnt[a[i]]) {
        --cnt[a[i]];
      }
      else {
        ans = 0;
        break;
      }
    }
    cout << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}