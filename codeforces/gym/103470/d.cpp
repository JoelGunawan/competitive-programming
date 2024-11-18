#include <bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define mp make_pair
#define ins insert
#define ll long long
#define endl "\n"
using namespace std;
struct fenwick {
  vector<int> a;
  fenwick(int n) {
    a = vector<int>(n + 5, 0);
  }
  void update(int idx, int val) {
    while(idx < a.size()) {
      a[idx] += val;
      idx += idx&-idx;
    }
  }
  int query(int idx) {
    int ret = 0;
    while(idx) {
      ret += a[idx];
      idx -= idx&-idx;
    }
    return ret;
  }
};
void tc() {
  int n;
  cin >> n;
  int a[n + 5];
  fenwick bit(n);
  int mx = 0;
  vector<int> seq;
  ll cur = 0;
  int cnt[n + 5];
  memset(cnt, 0, sizeof(cnt));
  int reserve = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    if(cnt[a[i]] == 0)
      bit.update(a[i], 1);
    if(a[i] > mx) {
      cur += cnt[mx] + reserve;
      // cout << "DEBUG " << reserve << " " << cnt[mx] << endl;
      reserve = 0;
      mx = a[i];
      seq.pb(a[i]);
    }
    else {
      cur += bit.query(n) - bit.query(a[i]);
      if(cnt[mx] > 1 && a[i] != mx)
        ++reserve;
    }
    // cout << cur << " " << seq.size() << " " << cnt[mx] << " ";
    ++cnt[a[i]];
    cout << cur + (int)seq.size() - 1;
    if(i != n)
      cout << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--)
    tc();
}