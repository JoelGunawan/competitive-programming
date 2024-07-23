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
  int n, m;
  cin >> n >> m;
  int a[m + 1];
  for(int i = 1; i <= m; ++i)
    cin >> a[i];
  int freq[n + 1];
  // untuk membuat semua nilai freq jadi 0, pakai memset
  // hanya utk set ke 0 atau -1
  memset(freq, 0, sizeof(freq));
  for(int i = 1; i <= m; ++i)
    ++freq[a[i]];
  int res = 0;
  for(int i = 1; i <= n; ++i) {
    if(freq[i] % 4 == 2 || freq[i] % 4 == 3)
      ++res;
  }
  cout << res << endl;
  return 0;
}