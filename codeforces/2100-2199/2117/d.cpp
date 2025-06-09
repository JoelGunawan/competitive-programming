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
void tc() {
  int n;
  cin >> n;
  int a[n + 5];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  if((2 * a[1] - a[2]) % (n + 1) == 0) {
    int x = (2 * a[1] - a[2]) / (n + 1);
    // cerr << "X " << x << endl;
    ll b[n + 1];
    for(int i = 1; i <= n; ++i) {
      b[i] = a[i];
    }
    if(x >= 0) {
      b[1] -= 1ll * x * (n + 1);
      int op1 = b[1];
      // cerr << "OP1 " << op1 << endl;
      if(b[1] >= 0) {
        for(int i = 2; i <= n; ++i) {
          b[i] -= 1ll * x * (n + 1);
          b[i] -= 1ll * op1 * i;
        }
        bool ans = 1;
        for(int i = 2; i <= n; ++i)
          ans &= b[i] == 0;
        if(ans) {
          cout << "YES" << endl;
          return;
        }
      }
    }
  }
  reverse(a + 1, a + n + 1);
  if((2 * a[1] - a[2]) % (n + 1) == 0) {
    int x = (2 * a[1] - a[2]) / (n + 1);
    if(x >= 0) {
      // cerr << "X " << x << endl;
      ll b[n + 1];
      for(int i = 1; i <= n; ++i) {
        b[i] = a[i];
      }
      b[1] -= 1ll * x * (n + 1);
      int op1 = b[1];
      // cerr << "OP1 " << op1 << endl;
      if(b[1] >= 0) {
        for(int i = 2; i <= n; ++i) {
          // cerr << "START " << b[i] << endl;
          // cerr << "X " << x << endl;
          b[i] -= 1ll * x * (n + 1);
          // cerr << "CUR " << b[i] << endl;
          // cerr << "REDUCE BY " << op1 * i << endl;
          b[i] -= 1ll * op1 * i;
          // cerr << b[i] << " ";
        }
        // cerr << endl;
        bool ans = 1;
        // cerr << b[1] << " " << b[2] << " " << op1 << endl;
        for(int i = 2; i <= n; ++i)
          ans &= b[i] == 0;
        if(ans) {
          cout << "YES" << endl;
          return;
        }
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}