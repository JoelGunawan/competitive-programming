#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// #define endl "\n"
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
  // ios_base::sync_with_stdio(0); cin.tie(NULL);
  vector<int> tmp;
  int x;
  while(cin >> x) {
    tmp.push_back(x);
  }
  int n = tmp.size() / 2;
  int a[n], b[n];
  for(int i = 0; i < n; ++i) {
    a[i] = tmp[i];
    b[i] = tmp[n + i];
  }

  int cnt = 0;
  for(int i = 0; i < n; ++i) {
    int pr = (i - 1 + n) % n, nx = (i + 1) % n;
    if(static_cast<int>(a[i] > b[i]) + (a[pr] > b[i]) + (a[nx] > b[i]) >= 2) {
      ++cnt;
    }

    if(static_cast<int>(b[i] > a[i]) + (b[pr] > a[i]) + (b[nx] > a[i]) >= 2) {
      ++cnt;
    }
  }

  assert(cnt == n + n / 2 + (n & 1) - 1);

  cout << "DONE" << endl;
  
  return 0;
}