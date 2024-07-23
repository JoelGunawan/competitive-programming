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
  int n, a, b;
  cin >> n >> a >> b;
  int sisa = n;
  for(int i = 2 * b; i <= n; i += b) {
    int req = (n - i) / a;
    req = min(req, i / b - 1);
    //cout << (n - i) << " " << req << endl;
    if(req > 0)
      sisa = min(sisa, (n - i) - a * req);
  }
  cout << sisa << endl;
  return 0;
}