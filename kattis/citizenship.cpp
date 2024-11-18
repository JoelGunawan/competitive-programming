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
  int n, y, d;
  cin >> n >> y >> d;
  vector<pair<vector<int>, vector<int>>> v;
  vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int lasty = 0;
  for(int i = 1; i <= n; ++i) {
    string a, b;
    cin >> a >> b;
    int y, m, d;
    y = stoi(a.substr(0, 4)), m = stoi(a.substr(5, 2)), d = stoi(a.substr(8, 2));
    // cerr << y << " " << m << " " << d << endl;
    v.pb(mp(vector<int>(), vector<int>()));
    // cerr << "AFTER" << endl;
    v[i - 1].fi = {y, m, d};
    y = stoi(b.substr(0, 4)), m = stoi(b.substr(5, 2)), d = stoi(b.substr(8, 2));
    v[i - 1].se = {y, m, d};
    lasty = max(y, lasty);
    // cerr << "FINALLY" << endl;
  }
  bool f[6005];
  memset(f, 0, sizeof(f));
  bool out[6005 * 365];
  memset(out, 0, sizeof(out));
  for(auto p : v) {
    int cury = p.fi[0], curm = p.fi[1], curd = p.fi[2];
    // cerr << "INIT" << endl;
    int sumd = 0;
    for(int i = 0; i < curm - 1; ++i)
      sumd += days[i];
    while(cury != p.se[0] || curm != p.se[1] || curd != p.se[2]) {
      // cerr << cury << " " << curm << " " << curd << endl;
      out[cury * 365 + curd + sumd] = true;
      ++curd;
      if(curd > days[curm - 1]) {
        curd = 1;
        sumd += days[curm - 1];
        if(curm == 12)
          curm = 1, ++cury, sumd = 0;
        else
          ++curm;
      }
    }
    out[cury * 365 + curd + sumd] = true;
    // cerr << "TST" << endl;
  }
  for(int i = 0; i <= 6000; ++i) {
    int cnt = 0;
    for(int j = 1; j <= 365; ++j) {
      if(out[i * 365 + j])
        ++cnt;
    } 
    f[i] = 365 - cnt >= d;
  }
  for(int i = lasty; i <= 6000; ++i) {
    bool can = 1;
    for(int j = lasty - y + 1; j <= lasty; ++j) {
      if(!f[j])
        can = false;
    }
    if(can) {
      // find closest
      for(int j = 1; j <= 365; ++j) {
        if(out[i * 365 + j])
          ++cnt;
        if(j - cnt >= d) {
          string month, day;
          
          cout << i << "-" << 
          exit(0);
        }
      }
    }
  }

  return 0;
}