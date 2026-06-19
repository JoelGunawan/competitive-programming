#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 998244353;
ll powmod(ll a, ll b) {
  if(b == 0) {
    return 1;
  }
  else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}

int dp[10][1000][1000][2][2];
int ndp[10][1000][1000][2][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  if (n > m) {
    swap(n, m);
  }

  if (n < 3) {
    cout << "0\n";
    return 0;
  }

  if (n > 8) {
    cout << powmod(2, n * m) << "\n";
    return 0;
  }

  vector<int> pw(n + 1);
  pw[0] = 1;
  for (int i = 1; i <= n; i++) {
    pw[i] = pw[i - 1] * 3;
  }

  auto trit = [&](int i) -> int {
    i--;
    return pw[i];
  };

  auto gettrit = [&](int x, int i) -> int {
    i--;
    return (x / pw[i]) % 3;
  };

  auto add = [&](int &a, int b) -> void {
    a += b;
    if (a >= mod)
      a -= mod;
  };

  dp[0][0][0][0][0] = 1;

  for (int rep = 0; rep < m; rep++) {
    bool found = false;
    for (int i = 0; i < n; i++) {
      for (int wmask = 0; wmask < trit(n - 1); wmask++) {
        for (int bmask = 0; bmask < trit(n - 1); bmask++) {
          for (int w = 0; w < 2; w++) {
            for (int b = 0; b < 2; b++) if (dp[i][wmask][bmask][w][b]) {
              found = true;
              int cur = dp[i][wmask][bmask][w][b];
              cerr << rep << " " << i << " " << wmask << " " << bmask << " " << w << " " << b << " " << cur << "\n";
              if (i == 0 || i == n - 1) {
                //place white
                add(dp[i + 1][wmask][bmask][1][b], dp[i][wmask][bmask][w][b]);
                // place black
                add(dp[i + 1][wmask][bmask][w][1], dp[i][wmask][bmask][w][b]);
              } else {
                //place white 
                if (gettrit(wmask, i) == 0) {
                  add(dp[i + 1][wmask + trit(i)][bmask][1][b], cur);
                } else if (gettrit(wmask, i) == 2) {
                  // butterfly 
                } else {
                  if (!w) {
                    add(dp[i + 1][wmask][bmask][1][b], cur);
                  } else {
                    add(dp[i + 1][wmask + trit(i)][bmask][1][b], cur);
                    // subtract the case where all cells below are black
  
                    bool good = true;
                    int newbmask = bmask;
                    for (int j = i + 1; j < n - 1; j++) {
                      if (gettrit(bmask, j) == 0) {
                        newbmask += trit(j);
                      } else if (gettrit(bmask, j) == 1) {
                        if (b || j > (i + 1)) {
                          newbmask += trit(j);
                        } 
                      } else if (gettrit(bmask, j) == 2) {
                        good = false;
                      }
                    }
  
                    if (good) {
                      add(dp[n][wmask + trit(i)][newbmask][1][1], mod - cur);
                      add(dp[n][wmask][newbmask][1][1], cur);
                    }
                  }
                }

                // place black
                if (gettrit(bmask, i) == 0) {
                  add(dp[i + 1][wmask][bmask + trit(i)][w][1], cur);
                } else if (gettrit(bmask, i) == 2) {
                  // butterfly 
                } else {
                  if (!b) {
                    add(dp[i + 1][wmask][bmask][w][1], cur);
                  } else {
                    add(dp[i + 1][wmask][bmask + trit(i)][w][1], cur);
                    // subtract the case where all cells below are white
  
                    bool good = true;
                    int newwmask = wmask;
                    for (int j = i + 1; j < n - 1; j++) {
                      if (gettrit(wmask, j) == 0) {
                        newwmask += trit(j);
                      } else if (gettrit(wmask, j) == 1) {
                        if (w || j > (i + 1)) {
                          newwmask += trit(j);
                        } 
                      } else if (gettrit(wmask, j) == 2) {
                        good = false;
                      }
                    }
  
                    if (good) {
                      add(dp[n][newwmask][bmask + trit(i)][1][1], mod - cur);
                      add(dp[n][newwmask][bmask][1][1], cur);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }

    if (!found) {
      cout << powmod(2, n * m) << "\n";
      return 0;
    }

    for (int wmask = 0; wmask < trit(n - 1); wmask++) {
      for (int bmask = 0; bmask < trit(n - 1); bmask++) {
        for (int w = 0; w < 2; w++) {
          for (int b = 0; b < 2; b++) {
            if (rep == 2 && wmask == 1 && bmask == 0) {
              cerr << w << " " << b << " " << dp[n][wmask][bmask][w][b] << "\n";
            }
            add(ndp[0][wmask][bmask][0][0], dp[n][wmask][bmask][w][b]);
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int wmask = 0; wmask < trit(n - 1); wmask++) {
        for (int bmask = 0; bmask < trit(n - 1); bmask++) {
          for (int w = 0; w < 2; w++) {
            for (int b = 0; b < 2; b++) {
              dp[i][wmask][bmask][w][b] = 0;       
            }
          }
        }
      }
    }

    swap(dp, ndp);
  }

  int ans = powmod(2, n * m);
  for (int wmask = 0; wmask < trit(n - 1); wmask++) {
    for (int bmask = 0; bmask < trit(n - 1); bmask++) {
      cerr << wmask << " " << bmask << " " << dp[0][wmask][bmask][0][0] << "\n";
      add(ans, mod - dp[0][wmask][bmask][0][0]);
    }
  }

  cout << ans << "\n";
}