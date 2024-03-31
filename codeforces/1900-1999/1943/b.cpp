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
int key, mod = 1e9 + 9;
bool modeq(ll a, ll b) {
  a %= mod;
  b %= mod;
  if(a < 0)
    a += mod;
  if(b < 0)
    b += mod;
  return a == b;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    key = rng();
    int n, q;
    cin >> n >> q;
    char a[n + 1];
    int pref[n + 1][26];
    memset(pref, 0, sizeof(pref));
    for(int i = 1; i <= n; ++i) {
      cin >> a[i];
      for(int j = 0; j < 26; ++j) {
        pref[i][j] = pref[i - 1][j];
      }
      ++pref[i][a[i] - 'a'];
    }
    int precons[n + 1];
    memset(precons, 0, sizeof(precons));
    for(int i = 1; i < n; ++i) {
      precons[i] = precons[i - 1];
      if(a[i] == a[i + 1])
        ++precons[i];
    }
    ll prehash[n + 1], sufhash[n + 2], power[n + 1];
    memset(prehash, 0, sizeof(prehash));
    memset(sufhash, 0, sizeof(sufhash));
    for(int i = 1; i <= n; ++i) {
      prehash[i] = (prehash[i - 1] * key + a[i]) % mod;
    }
    for(int i = n; i >= 1; --i) {
      sufhash[i] = (sufhash[i + 1] * key + a[i]) % mod;
    }
    power[0] = 1;
    for(int i = 1; i <= n; ++i) {
      power[i] = (power[i - 1] * key) % mod;
    }
    while(q--) {
      int l, r;
      cin >> l >> r;
      int cntu = 0;
      for(int i = 0; i < 26; ++i) {
        if(pref[r][i] - pref[l - 1][i])
          ++cntu;
      }
      if(cntu == 1) {
        cout << 0 << endl;
      }
      else if(cntu == 2) {
        // check full alternate
        if(precons[r - 1] - precons[l - 1]) {
          // not full alternate
          // check length
          if(modeq(prehash[r] - prehash[l - 1] * power[r - l + 1], sufhash[l] - sufhash[r + 1] * power[r - l + 1])) {
            cout << 1ll * (r - l + 1) * (r - l) / 2 - 1 << endl;
          }
          else {
            cout << 1ll * (r - l + 1) * (r - l + 2) / 2 - 1 << endl;
          }
        }
        else {
          // full alternate, only even one can work
          int x = r - l + 1;
          x /= 2;
          //cout << "FULL ALT" << endl;
          cout << 1ll * x * (x + 1) << endl;
        }
        //cout << "WIP" << endl;
      }
      else {
        if(modeq(prehash[r] - prehash[l - 1] * power[r - l + 1], sufhash[l] - sufhash[r + 1] * power[r - l + 1])) {
          cout << 1ll * (r - l + 1) * (r - l) / 2 - 1 << endl;
        }
        else {
          cout << 1ll * (r - l + 1) * (r - l + 2) / 2 - 1 << endl;
        }
      }
    }
  }
  return 0;
}