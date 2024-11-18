// header file
#include <bits/stdc++.h>
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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll i = 1; i <= n; ++i)
      cin >> v[i - 1];
    ll pref[n + 1];
    memset(pref, 0, sizeof(pref));
    for(ll i = 1; i <= n; ++i)
      pref[i] = pref[i - 1] + v[i - 1];
    ll x = 0;
    for(ll i = 1; i <= min(n / 2 + 500, 500ll); ++i) {
      for(ll j = 1; j + i - 1 <= n; ++j) {
        if(pref[i + j - 1] - pref[j - 1] == 1ll * i * i) {
          ++x;
        }
      }
    }
    for(ll i = max(n / 2 - 500, 501ll); i <= min(n, n / 2 + 500); ++i) {
      for(ll j = 1; j + i - 1 <= n; ++j) {
        if(pref[i + j - 1] - pref[j - 1] == 1ll * i * i) {
          ++x;
        }
      }
    }
    cout << x << endl;
  }
  return 0;
}