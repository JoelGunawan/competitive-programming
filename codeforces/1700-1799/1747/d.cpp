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
  int n, q;
  cin >> n >> q;
  int zero[n + 1];
  ll pref[n + 1];
  memset(pref, 0, sizeof(pref));
  memset(zero, 0, sizeof(zero));
  int a[n + 1];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    zero[i] = zero[i - 1];
    if(a[i] == 0)
      ++zero[i];
    pref[i] = pref[i - 1] ^ a[i];
  }
  map<ll, vector<int>> v[2];
  for(int i = 0; i <= n; ++i) {
    v[i & 1][pref[i]].pb(i);
  }
  while(q--) {
    int l, r;
    cin >> l >> r;
    if(pref[r] ^ pref[l - 1]) {
      cout << -1 << endl;
    }
    else if(zero[r] - zero[l - 1] == r - l + 1) {
      cout << 0 << endl;
    }
    else if((r - l + 1) & 1 || a[l] == 0 || a[r] == 0) {
      cout << 1 << endl;
    }
    else {
      // need to find a point that has xor 0 in the middle
      // find occurence of pref[r] between l to r - 1 with equal parity to l
      if(ub(v[l & 1][pref[r]].begin(), v[l & 1][pref[r]].end(), r) - lb(v[l & 1][pref[r]].begin(), v[l & 1][pref[r]].end(), l)) {
        cout << 2 << endl;
      }
      else {
        cout << -1 << endl;
      }
    }
  }
  return 0;
}