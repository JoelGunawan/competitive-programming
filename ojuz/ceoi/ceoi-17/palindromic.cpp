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
    int mod = 1e9 + 9;
    mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
    while(t--) {
      string s;
      cin >> s;
      int n = s.size();
      s = " " + s;
      ll pre = 0, suff = 0, suffpow = 1;
      // do hashing prefix suffix
      // if we can find a match, directly match
      int cnt = 0;
      int key = rng() % mod;
      for(int i = 1; i <= (n / 2); ++i) {
        pre = ((pre * key) % mod + s[i]) % mod;
        suff = (suff + (suffpow * s[n - i + 1]) % mod) % mod;
        suffpow = (suffpow * key) % mod;
        if(pre == suff) {
          pre = 0, suff = 0, suffpow = 1;
          cnt += 2;
        }
      }
      if(pre != 0)
        ++cnt;
      else if(pre == 0 && (n & 1))
        ++cnt;
      cout << cnt << endl;
    }
    return 0;
}