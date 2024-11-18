#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define endl "\n"
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for(int i = 0; i < n; ++i)
    cin >> v[i].fi >> v[i].se;
  int m;
  cin >> m;
  int a[m + 5];
  for(int i = 1; i <= m; ++i)
    cin >> a[i];
  v.pb(mp(-1, 0));
  v.pb(mp((int)1e9 + 1, (int)1e9 + 5));
  sort(v.begin(), v.end());
  int maxR = -2;
  vector<pair<int, int>> tmp;
  for(auto x : v) {
    if(x.se > maxR)
      tmp.pb(x);
    maxR = max(maxR, x.se);
  }
  v = tmp;
  int cur = 1;
  int res = -1;
  while(cur <= m) {
    ++res;
    // pilih gigi yg mgkn utk next
    // kita gaperlu tau itu gigi apa
    int l, r;
    int cl = 0, cr = v.size() - 1;
    // find smallest l such that r >= a[cur]
    while(cl <= cr) {
      int mid = (cl + cr) >> 1;
      // cout << mid << " " << v[mid].se << " " << a[cur] << endl;
      if(v[mid].se >= a[cur])
        l = mid, cr = mid - 1;
      else
        cl = mid + 1;
    }
    cl = 0, cr = v.size() - 1;
    // find largest l that it is <= a[cur]
    while(cl <= cr) {
      int mid = (cl + cr) >> 1;
      if(v[mid].fi <= a[cur])
        r = mid, cl = mid + 1;
      else
        cr = mid - 1;
    }
    if(l > r) {
      cout << -1 << endl;
      exit(0);
    }
    // cout << "OUTPUT L R " << cur << " " << l << " " << r << endl;
    // got l, r now go to next and find gigi there
    while(cur < m) {
      int nxl, nxr;
      cl = 0, cr = v.size() - 1;
      while(cl <= cr) {
        int mid = (cl + cr) >> 1;
        if(v[mid].se >= a[cur + 1])
          nxl = mid, cr = mid - 1;
        else
          cl = mid + 1;
      }
      cl = 0, cr = v.size() - 1;
      // find largest l that it is <= a[cur]
      while(cl <= cr) {
        int mid = (cl + cr) >> 1;
        if(v[mid].fi <= a[cur + 1])
          nxr = mid, cl = mid + 1;
        else
          cr = mid - 1;
      }
      if(max(nxl, l) <= min(nxr, r)) {
        // good, go to next
        l = max(nxl, l);
        r = min(nxr, r);
        ++cur;
      }
      else
        break;
    }
    ++cur;
  }
  cout << res << endl;
}