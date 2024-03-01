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
  while(t--) {
    int n;
    string s;
    cin >> n >> s;
    int lcnt[n], rcnt[n];
    int cur = 0;
    for(int i = 0; i < n; ++i) {
      lcnt[i] = cur;
      if(s[i] == '>')
        ++cur;
    }
    cur = 0;
    for(int i = n - 1; i >= 0; --i) {
      rcnt[i] = cur;
      if(s[i] == '<')
        ++cur;
    }
    int lq[n], rq[n];
    ll ops[n];
    memset(ops, 0, sizeof(ops));
    for(int i = 0; i < n; ++i) {
      if(s[i] == '<') {
        // L first
        if(rcnt[i] < lcnt[i]) {
          // ikut rcnt
          rq[i] = rcnt[i];
          lq[i] = rcnt[i] + 1;
          ops[i] += n - i;
        }
        else {
          lq[i] = lcnt[i];
          rq[i] = lcnt[i];
          ops[i] += i + 1;
        }
      }
      else {
        // R first
        if(lcnt[i] < rcnt[i]) {
          // ikut lcnt
          lq[i] = lcnt[i];
          rq[i] = lcnt[i] + 1;
          ops[i] += i + 1;
        }
        else {
          rq[i] = rcnt[i];
          lq[i] = rcnt[i];
          ops[i] += n - i;
        }
      }
    }
    vector<ll> pre = {0};
    //cout << "CONSIDER LEFT " << endl;
    for(int i = 0; i < n; ++i) {
      ops[i] += 2 * (1ll * i * lq[i] - (pre.back() - pre[pre.size() - lq[i] - 1]));
      //cout << 2 * (1ll * i * lq[i] - (pre.back() - pre[pre.size() - lq[i] - 1])) << " ";
      if(s[i] == '>')
        pre.pb(pre.back() + i);
    }
    //cout << endl;
    pre = {0};
    //cout << "CONSIDER RIGHT" << endl;
    for(int i = n - 1; i >= 0; --i) {
      ops[i] += 2 * (1ll * (n - i) * rq[i] - (pre.back() - pre[pre.size() - rq[i] - 1]));
      //cout << (pre.back() - pre[pre.size() - rq[i] - 1]) << " ";
      //cout << 2 * (1ll * (n - i) * rq[i] - (pre.back() - pre[pre.size() - rq[i] - 1])) << " ";
      if(s[i] == '<')
        pre.pb(pre.back() + n - i);
    }
    //cout << endl;
    //cout << "LQ" << endl;
    //for(auto i : lq)
      //cout << i << " ";
    //cout << endl;
    //cout << "RQ" << endl;
    //for(auto i : rq)
      //cout << i << " ";
    //cout << endl;
    for(auto i : ops)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}