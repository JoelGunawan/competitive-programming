#include "trainer.h"

#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
vector<vector<ll>> a;
vector<vector<ll>> pref;
vector<pair<ll, ll>> b;
ll dnc(ll al, ll ar, ll bl, ll br) {
  if(al > ar)
    return 0;
  assert(bl <= br);
  assert(al <= ar);
  ll mid = (al + ar) / 2;
  ll optb = bl, optbr = bl; ll minima = 5e18;
  for(ll i = bl; i <= br; ++i) {
    ll le = lower_bound(a[mid].begin(), a[mid].end(), b[i].fi) - a[mid].begin();
    ll ge = a[mid].end() - upper_bound(a[mid].begin(), a[mid].end(), b[i].se);
    ll cur = 0;
    if(le)
      cur += 1ll * le * b[i].fi - pref[mid][le - 1];
    if(ge) {
      if(ge >= pref[mid].size()) 
        cur += pref[mid].back() - 1ll * ge * b[i].se;
      else
        cur += (pref[mid].back() - pref[mid][pref[mid].size() - ge - 1]) - 1ll * ge * b[i].se;
    }
    if(cur < minima)
      optb = i, optbr = i, minima = cur;
  } 
  assert(minima < 5e18);
  //assert(minima >= 0);
  return minima + dnc(al, mid - 1, bl, optb) + dnc(mid + 1, ar, optb, br);
}
long long minimize_penalty(std::vector<int> L, std::vector<int> R, std::vector<std::vector<int>> A) {
  ll K = L.size();
  ll M = A.size();
  ll N = A[0].size() / 2;
  for(ll i = 0; i < M; ++i)
    sort(A[i].begin(), A[i].end());
  for(ll i = 0; i < N; ++i) {
    vector<ll> tmp;
    for(ll j = 0; j < M; ++j)
      tmp.push_back(A[j][2 * i]), tmp.push_back(A[j][2 * i + 1]);
    sort(tmp.begin(), tmp.end());
    a.push_back(tmp);
    vector<ll> tmp2 = {tmp[0]};
    for(int j = 1; j < 2 * M; ++j) {
      tmp2.push_back(tmp2.back() + tmp[j]);
    }
    pref.push_back(tmp2);
  }
  vector<pair<ll, ll>> tmp2;
  for(ll i = 0; i < K; ++i)
    tmp2.push_back({L[i], -R[i]});
  sort(tmp2.begin(), tmp2.end());
  ll maxR = -100;
  for(ll i = 0; i < tmp2.size(); ++i) {
    if(-tmp2[i].se > maxR)
      b.push_back({tmp2[i].fi, -tmp2[i].se});
    maxR = max(maxR, -tmp2[i].se);
  }
  sort(b.begin(), b.end());
  assert(b.size() && a.size());
  assert(a.size() == pref.size());
  return dnc(0, N - 1, 0, b.size() - 1);
}