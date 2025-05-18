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
  int n, k;
  cin >> n >> k;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  ll pref[n + 5];
  pref[0] = 0;
  int prefcnt[n + 5];
  memset(pref, 0, sizeof(pref));
  memset(prefcnt, 0, sizeof(prefcnt));
  prefcnt[0] = 0;
  for(int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + a[i];
    prefcnt[i] = prefcnt[i - 1] + (a[i] == 0);
  }
  ll res = -1;
  for(int i = 0; i <= n; ++i) {
    for(int j = 0; j <= n; ++j) {
      if(i == j)
        continue;
      int cntin = prefcnt[max(i, j)] - prefcnt[min(i, j)], cnt = prefcnt[n];
      if(1ll * cnt * k >= abs(pref[n])) {
        // can return to 0
        // assume pref[i] < pref[j]
        ll cur = pref[j] - pref[i] + 1;
        ll tmp =  abs(pref[n]) / k;
        if(i < j) {
          if(pref[n] > 0) {
            // need to -, try to avoid cntin
            cnt -= tmp;
            if(cntin > cnt) {
              cur -= 1ll * (cntin - cnt) * k;
              cntin = cnt;
            }
          }
          else {
            // need to +, use cntin
            int mn = min((ll)cntin, tmp);
            cur += 1ll * mn * k;
            cntin -= mn;
            cnt -= tmp;
          }
        }
        else {
          if(pref[n] < 0) {
            // need to +, try to avoid cntin
            cnt -= tmp;
            if(cntin > cnt) {
              cur -= 1ll * (cntin - cnt) * k;
              cntin = cnt;
            }
          }
          else {
            // need to -, use cntin
            int mn = min((ll)cntin, tmp);
            cur += 1ll * mn * k;
            cntin -= mn;
            cnt -= tmp;
          }
        }
        int cntout = cnt - cntin;
        if(pref[n] % k == 0)
          cur += 1ll * min(cntin, cntout) * k;
        else if(cntin > 0) {
          if(i > j) {
            if(cntin <= cntout - 1) {
              // less than half of cnt and we have 1 extra cntout, optimize pref[n] % k part
              cur += 1ll * cntin * k;
            }
            else if(cntin == cntout) {
              cur += 1ll * (cntin - 1) * k;
              if(pref[n] % k > 0)
                cur += k;
              else
                cur += k + pref[n] % k;
            }
            else {
              // too much cntin
              cur += 1ll * cntout * k;
              cur += pref[n] % k;
            }
          }
          else {
            if(cntin <= cntout - 1) {
              // less than half of cnt and we have 1 extra cntout, optimize pref[n] % k part
              cur += 1ll * cntin * k;
            }
            else if(cntin == cntout) {
              cur += 1ll * (cntin - 1) * k;
              if(pref[n] % k < 0)
                cur += k;
              else
                cur += k - pref[n] % k;
            }
            else {
              // too much cntin
              cur += 1ll * cntout * k;
              cur -= pref[n] % k;
            }
          }
        }
        res = max(res, cur);
        // cerr << i << " " << j << " " << cur << " " << cntin << " " << cnt - cntin << endl;
      }
    }
  }
  cout << res << endl;
  return 0;
}