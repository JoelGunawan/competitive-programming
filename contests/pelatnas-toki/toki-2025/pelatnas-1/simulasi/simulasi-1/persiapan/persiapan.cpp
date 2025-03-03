#include "persiapan.h"
#include <bits/stdc++.h>
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
int inf = 1e9;
std::vector<int> persiapan(int N, std::vector<int> X) {
  int n;
  n = N;
  int a[n + 1];
  for(int i = 1; i <= n; ++i)
    a[i] = X[i - 1];
  // for each int, we need to know it's pair
  vector<int> v[n + 1];
  bool to_par[n + 1];
  memset(to_par, 0, sizeof(to_par));
  // go to parent with the values you have and find whether it is possible
  // fi -> idx, se -> moment when split
  int res[n + 1];
  v[1].pb(a[1]);
  // have counter of how many allowed to go to parent, so -- instead?
  for(int i = 1; i <= n; ++i) {
    pair<int, int> mn = mp(inf, inf);
    int cur = i;
    // cerr << i << endl;
    while(true) {
      // mark where we should stop, the child of that should be not allowed to go
      // cerr << "AT PARENT " << cur << endl;
      if(v[cur].size()) {
        sort(v[cur].begin(), v[cur].end(), greater<int>());
        mn = min(mn, mp(v[cur].back(), cur));
      }
      // cerr << "DEBUG " << cur << endl;
      if(!to_par[cur])
        break;
      cur >>= 1;
    }
    // keep in mind that we can use both left and right childs too
    // left child -> to_par[right] false
    if(2 * i <= n) {
      mn = min(mn, mp(a[2 * i], 2 * i));
    }
    if(2 * i + 1 <= n) {
      mn = min(mn, mp(a[2 * i + 1], 2 * i + 1));
    }
    // cerr << "FOUND MN " << mn.fi << " " << mn.se << endl;
    // cerr << "TO_PAR " << to_par[i] << endl;
    res[i] = mn.fi;
    if(mn.se == 2 * i) {
      // use a[2 * i] here
      to_par[2 * i] = 1;
      // push right if exists
      if(2 * i + 1 <= n)
        v[2 * i + 1].pb(a[2 * i + 1]);
    }
    else if(mn.se == 2 * i + 1) {
      // use a[2 * i + 1] here
      // whatever in v[i] or parents of it can go to both directions
      to_par[2 * i] = to_par[2 * i + 1] = 1;
      v[i].pb(a[2 * i]);
    }
    else {
      // any child can not go to parent
      // set in our direction that it is not allowed (unless it is at current, then it doesn't matter)
      if(2 * i <= n)
        v[2 * i].pb(a[2 * i]);
      if(2 * i + 1 <= n)
        v[2 * i + 1].pb(a[2 * i + 1]);
      if(mn.se != i) {
        int cur = i;
        // cerr << cur << " " << mn.se << endl;
        while(cur != mn.se) {
          to_par[cur] = 0;
          cur >>= 1;
        }
        // cerr << "DELETE " << mn.se << endl;
        v[mn.se].pop_back();
      }
    }
  }
  vector<int> ret(n);
  for(int i = 1; i <= n; ++i)
    ret[i - 1] = res[i];
  return ret;
}