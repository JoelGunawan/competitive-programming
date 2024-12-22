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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  string s;
  cin >> n >> s;
  vector<ll> pref, suff;
  pref = {0};
  suff = {n - 1};
  for(int i = n - 1; i >= 0; --i) {
    if(s[i] == 'D')
      suff.pb(suff.back() + i);
  }
  for(int i = 0; i < n; ++i) {
    if(suff.size() > 1 && suff.back() - suff[suff.size() - 2] == i)
      suff.pop_back();
    ll cur = 0;
    if(s[i] == 'U') {
      if(suff.size() <= pref.size()) {
        // end at right
        // cerr << "SIZE " << suff.size() << " " << pref.size() << endl;
        cur += 1ll * 2 * (suff.back() - 1ll * i * suff.size()) - (n - i - 2) - suff.size();
        // cerr << "RIGHT " << i << " " << cur << endl;
        cur += 1ll * 2 * (1ll * i * (suff.size() - 1) - (pref.back() - pref[pref.size() - suff.size()])) - (suff.size() - 1); 
        // cerr << "LEFT " << i << " " << cur << endl;
        cur += 2 * suff.size() - 1; 
        // cerr << "ADD CUR " << i << " " << cur << endl;
      }
      else {
        // end at left
        cur += 1ll * 2 * (1ll * i * pref.size() - pref.back()) - (i - 1) - pref.size();
        cur += 1ll * 2 * (suff.back() - suff[suff.size() - pref.size() - 1] - 1ll * i * pref.size()) - pref.size();
        cur += 2 * pref.size();
      }
    }
    else {
      if(pref.size() <= suff.size()) {
        cur += 1ll * 2 * (1ll * pref.size() * i - pref.back()) - (i - 1) - pref.size();
        cur += 1ll * 2 * (suff.back() - suff[suff.size() - pref.size()] - 1ll * i * (pref.size() - 1)) - (pref.size() - 1);
        cur += 2 * pref.size() - 1;
      }
      else {
        cur += 1ll * 2 * (suff.back() - 1ll * suff.size() * i) - (n - i - 2) - suff.size();
        cur += 1ll * 2 * (1ll * i * (suff.size()) - (pref.back() - pref[pref.size() - suff.size() - 1])) - suff.size();
        cur += 2 * suff.size();
      }
    }
    cout << cur << " ";
    if(s[i] == 'U')
      pref.pb(pref.back() + i);
  }
  cout << endl;
  return 0;
}