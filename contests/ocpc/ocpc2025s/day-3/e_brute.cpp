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
int main() {
  int sz = 7;
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  ll supermask = 1ll << (sz * sz);
  --supermask;
  ll it = 0;
  for(;;) {
    ll mask = supermask & rng();
    ++it;
    if(it == 1000000000) {
      cout << "IT " << it << endl;
    }
    
    bool a[sz][sz];
    for(int i = 0; i < sz; ++i) {
      for(int j = 0; j < sz; ++j) {
        a[i][j] = (1ll << (i * sz + j)) & mask;
      }
    }

    bool ans = 1;
    for(int i = 1; i < sz - 1; ++i) {
      for(int j = 1; j < sz - 1; ++j) {
        int found = 0;
        for(int k = 0; k < j; ++k) {
          if(a[i][j] == a[i][k]) {
            ++found;
            break;
          }
        }
        for(int k = j + 1; k < sz; ++k) {
          if(a[i][j] == a[i][k]) {
            ++found;
            break;
          }
        }
        for(int k = 0; k < i; ++k) {
          if(a[i][j] == a[k][j]) {
            ++found;
            break;
          }
        }

        for(int k = i + 1; k < sz; ++k) {
          if(a[i][j] == a[k][j]) {
            ++found;
            break;
          }
        }
        
        if(found == 4) {
          ans = 0;
          break;
        }
      }
      if(!ans)
        break;
    }
    
    if(ans) {
      for(int ii = 0; ii < sz; ++ii) {
        for(int jj = 0; jj < sz; ++jj) {
          cout << a[ii][jj];
        }
        cout << endl;
      }
      cout << endl;
    }
  }
}