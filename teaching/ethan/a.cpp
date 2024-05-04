#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
int main() {
  int n;
  cin >> n;
  pair<int, int> a[n];
  for(int i = 0; i < n; ++i) {
    cin >> a[i].fi;
    a[i].second = i;
  }
  sort(a, a + n);
  ll sum = 0;
  map<int, int> occur;
  ll ans[n];
  // 4 4 4 5 5
  // ans trkhr -> 0
  // ans kedua trkhr -> 0, tapi sumnya 5
  for(int i = n - 1; i >= 0; --i) {
    // proses...
    ans[a[i].se] = sum - (ll)occur[a[i].fi] * a[i].fi;
    sum += a[i].fi;
    ++occur[a[i].fi];
  }
  for(int i = 0; i < n; ++i)
    cout << ans[i] << " ";
  cout << endl;
}