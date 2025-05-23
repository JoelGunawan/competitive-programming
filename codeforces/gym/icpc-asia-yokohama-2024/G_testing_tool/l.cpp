#include <bits/stdc++.h>
#define ll long long 
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

template<typename T1, typename T2> 
bool mini(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
};

template<typename T1, typename T2> 
bool maxi(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, d, k;
  cin >> n >> d >> k;
  vector<ll> sum(n);
  for (int i = 0; i < n; i++) {
    cin >> sum[i];
  }

  for (int i = 1; i < n; i++) {
    sum[i] += sum[i - 1];
  }

  auto getsum = [&](int l, int r) -> ll {
    ll res = sum[r];
    if (l > 0) {
      res -= sum[l - 1];
    }
    return res;
  };

  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  vector<vector<int>> mx(n, vector<int>(n, 0));

  for (int len = 1; len <= n; len++) {
    for (int l = 0, r = len - 1; r < n; l++, r++) {
      // if (getsum(l, r) % d == k) {
      //   cerr << l << " " << r << "\n";
      //   maxi(mx[l][r], 1);
      // }

      for (int mid = l; mid < r; mid++) {
        maxi(mx[l][r], mx[l][mid] + mx[mid + 1][r]);
      }

      if (getsum(l, r) % d == (ll) k * (mx[l][r] + 1) % d) {
        mx[l][r]++;
      } 
    }
  }

  for (int len = 1; len <= n; len++) {
    for (int l = 0, r = len - 1; r < n; l++, r++) {
      for (int cnt = 0; cnt <= mx[l][r]; cnt++) {
        if ((ll) (cnt + 1) * k % d == getsum(l, r) % d) {
          maxi(dp[l][r], getsum(l, r) - (ll) (cnt + 1) * k);
        }
      }
      for (int mid = l; mid < r; mid++) {
        maxi(dp[l][r], dp[l][mid] + dp[mid + 1][r]);
      }
    }
  }

  // for (int i = 0; i < n; i++) {
  //   for (int j = i + 1; j < n; j++) {
  //     cerr << i << " " << j << " " << mx[i][j] << " " << dp[i][j] << "\n";
  //   }
  // }

  cout << dp[0][n - 1] / d << "\n";
}