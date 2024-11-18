#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
  int n, k, t;
  cin >> n >> k >> t;
  ll s[n + 2];
  s[0] = 1e9 + 5, s[n + 1] = 1e9 + 5;
  for(int i = 1; i <= n; ++i) {
    cin >> s[i];
  } 
  int indiv[k + 2];
  indiv[0] = 0, indiv[k + 1] = n + 1;
  for(int i = 1; i <= k; ++i) 
    cin >> indiv[i];
  ll pref[n + 2], suff[n + 2];
  sort(indiv + 1, indiv + k + 1);
  memset(pref, 0, sizeof(pref));
  memset(suff, 0, sizeof(suff));
  ll cur = 0;
  vector<ll> v;
  for(int i = 1; i <= k + 1; ++i) {
    // check segment i - 1 to i
    ll now = 0;
    for(int j = indiv[i - 1] + 1; j < indiv[i]; ++j)
      now += s[j] - min(s[indiv[i - 1]], s[indiv[i]]);
    // cout << now << endl;
    cur += now;
    ll tmp = now;
    // choose pref suff such that deleting the middle would be optimum
    now = 0;
    for(int j = indiv[i - 1] + 1; j < indiv[i]; ++j) {
      now += s[j] - s[indiv[i - 1]];
      pref[j] = max(pref[j - 1], now);
    }
    now = 0;
    for(int j = indiv[i] - 1; j > indiv[i - 1]; --j) {
      now += s[j] - s[indiv[i]];
      suff[j] = max(suff[j + 1], now);
    }
    ll mx = now;
    for(int j = indiv[i - 1]; j < indiv[i]; ++j) {
      mx = max(mx, pref[j] + suff[j + 1]);
    }
    // cout << "OUT PREF SUFF" << endl;
    // for(int j = indiv[i - 1] + 1; j < indiv[i]; ++j)
    //   cout << pref[j] << " ";
    // cout << endl;
    // for(int j = indiv[i] - 1; j > indiv[i - 1]; --j)
    //   cout << suff[j] << " ";
    // cout << endl;
    // cout << mx << " " << tmp << " " << mx - tmp << endl;
    v.pb(mx - tmp);
  }
  if(v.size())
    sort(v.begin(), v.end());
  t -= k;
  while(v.size() && t) {
    --t;
    cur += v.back();
    v.pop_back();
  }
  cout << cur << endl;
  return 0;
}