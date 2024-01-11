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
int mod = 998244353;
ll powmod(ll a, ll b) {
  if(b == 0)
    return 1;
  else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
ll add(ll a, ll b) {
  return (a + b) % mod;
}
ll mul(ll a, ll b) {
  return (a * b) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    // observe: if n * m is odd, then any config works
    // if n * m is even, then only if count of both odd is even and even is odd
    if((1ll * n * m) & 1) {
      // literally any L, R
      cout << powmod(r - l + 1, 1ll * n * m) << endl;
    }
    else {
      ll even_cnt = r / 2 - (l - 1) / 2, odd_cnt = (r - l + 1) - even_cnt;
      // we can find count of odd and even of a certain size using dnc
      ll line[30][2];
      memset(line, 0, sizeof(line));
      //cout << even_cnt << " " << odd_cnt << endl;
      line[0][0] = even_cnt, line[0][1] = odd_cnt;
      for(int i = 1; i < 30; ++i) {
        line[i][0] = add(mul(line[i - 1][0], line[i - 1][0]), mul(line[i - 1][1], line[i - 1][1]));
        line[i][1] = mul(2, mul(line[i - 1][0], line[i - 1][1]));
        //cout << "DEBUG LINE " << line[i][0] << " " << line[i][1] << endl;
      }
      ll grid[30][2];
      memset(grid, 0, sizeof(grid));
      grid[0][0] = 1, grid[0][1] = 0;
      for(int i = 29; i >= 0; --i) {
        if(n & (1 << i)) {
          ll tmp0 = grid[0][0], tmp1 = grid[0][1];
          grid[0][0] = add(mul(tmp0, line[i][0]), mul(tmp1, line[i][1]));
          grid[0][1] = add(mul(tmp0, line[i][1]), mul(tmp1, line[i][0]));
        }
      }
      //cout << "INIT GRID " << grid[0][0] << " " << grid[0][1] << endl;
      for(int i = 1; i < 30; ++i) {
        grid[i][0] = add(mul(grid[i - 1][0], grid[i - 1][0]), mul(grid[i - 1][1], grid[i - 1][1]));
        grid[i][1] = mul(2, mul(grid[i - 1][0], grid[i - 1][1]));
        //cout << "DEBUG GRID " << grid[i][0] << " " << grid[i][1] << endl;
      }
      ll res_odd = 0, res_even = 1;
      for(int i = 29; i >= 0; --i) {
        if(m & (1 << i)) {
          ll tmp0 = res_even, tmp1 = res_odd;
          res_even = add(mul(tmp0, grid[i][0]), mul(tmp1, grid[i][1]));
          res_odd = add(mul(tmp0, grid[i][1]), mul(tmp1, grid[i][0]));
        }
      }
      cout << res_even << endl;
    }
    return 0;
}