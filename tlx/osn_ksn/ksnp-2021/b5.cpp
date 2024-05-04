#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
  return 1ll * a.first * b.second < 1ll * a.second * b.first;
}
ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, a, b, q;
  cin >> n >> m >> a >> b >> q;
  cout << fixed << setprecision(10);
  while(q--) {
    ll x;
    cin >> x;
    // bsta ld, find count equals to x
    long double l = 0, r = 1e9, ans;
    while(r - l > 1e-15) {
      long double mid = (l + r) / 2;
      ll cnt = 0;
      for(int i = 1; i <= n; ++i) {
        // (b + j) / (a + i) <= mid
        // b + j <= mid * (a + i)
        // j <= mid * (a + i) - b
        if((ll)(mid * (a + i) - b) > 0)
          cnt += min((ll)m, (ll)(mid * (a + i) - b));
      }
      //cout << l << " " << r << " " << mid << " " << cnt << " " << x << endl;
      if(cnt > x) {
        r = mid;
        ans = mid;
      }
      else if(cnt == x) {
        ans = mid;
        break;
      }
      else {
        l = mid;
      }
    }
    //cout << ans << endl;
    vector<pair<int, int>> arr;
    for(int i = 1; i <= n; ++i) {
      //cout << (ans * (a + i) - b) << endl;
      if((ll)(ans * (a + i) - b) > 0)
        arr.push_back(mp(b + min((ll)m, (ll)(ans * (a + i) - b)), a + i));
    }
    pair<int, int> mx = mp(1, 2e9);
    //cout << "DEBUG" << endl;
    for(auto v : arr) {
      //cout << v.fi << " " << v.se << endl;
      mx = max(mx, v, compare);
    }
    //cout << endl;
    int y = gcd(mx.fi, mx.se);
    mx.fi /= y, mx.se /= y;
    cout << mx.fi << "/" << mx.se << endl;
  }

  
}