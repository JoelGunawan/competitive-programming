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
const int dim = 32;
int a[32][32];
int main() {
  // ios_base::sync_with_stdio(0); cin.tie(NULL);
  int arr[4] = {1, 0, 0, 1};
  int sz = 16;
  for(int i = 9; i >= 0; i -= 2) {
    for(int j = 0; j < dim / sz; ++j) {
      for(int k = sz * j; k < sz * j + sz; ++k) {
        for(int l = 0; l < dim; ++l)
          a[k][l] |= (arr[j & 3] << i);
      }
    }
    sz >>= 1;
  }
  sz = 16;
  for(int i = 8; i >= 0; i -= 2) {
    for(int j = 0; j < dim / sz; ++j) {
      for(int k = sz * j; k < sz * j + sz; ++k) {
        for(int l = 0; l < dim; ++l)
          a[l][k] |= (arr[j & 3] << i);
      }
    }
    sz >>= 1;
  }
  set<int> s;
  ll cost = 0;
  // for(int i = 0; i < 32; ++i)
  //   for(int j = 0; j < 32; ++j) {
  //     s.ins(a[i][j]);
  //   }
  int cnt[10];
  memset(cnt, 0, sizeof(cnt));
  for(int i = 0; i < 32; ++i) {
    for(int j = 0; j < 32; ++j) {
      if(j != 31)
        cost += a[i][j] ^ a[i][j + 1];
      if(i != 31)
        cost += a[i][j] ^ a[i + 1][j];
      // int x = a[i][j] ^ a[i][j + 1], y = a[i][j] ^ a[i + 1][j];
      // for(int k = 0; k < 10; ++k) {
      //   if((1 << k) & x)
      //     ++cnt[k];
      //   if((1 << k) & y)
      //     ++cnt[k];
      // }
    }
  }
  // for(int i = 0; i < 10; ++i)
  //   cerr << cnt[i] << " ";
  // cerr << endl;
  // cerr << cost << " " << s.size() << endl;
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n - 1; ++j) {
      cout << (a[i][j] ^ a[i][j + 1]) << " ";
    }
    cout << endl;
  }
  for(int i = 0; i < n - 1; ++i) {
    for(int j = 0; j < n; ++j) {
      cout << (a[i][j] ^ a[i + 1][j]) << " ";
    }
    cout << endl;
  }
  // for(int i = 0; i < 2; ++i) {
  //   for(int j = 0; j < 2; ++j)
  //     cerr << a[i][j] << " ";
  //   cerr << endl;
  // }
  int ref = a[0][0];
  while(k--) {
    int x;
    cin >> x;
    bool found = 0;
    for(int i = 0; i < 32; ++i) {
      for(int j = 0; j < 32; ++j) {
        // cerr << a[i][j] << " " << ref << " " << x << endl;
        if((a[i][j] ^ ref) == x) {
          cout << i + 1 << " " << j + 1 << endl, ref = a[i][j];
          found = 1;
          break;
        }
      }
      if(found)
        break;
    }
  }
  return 0;
}