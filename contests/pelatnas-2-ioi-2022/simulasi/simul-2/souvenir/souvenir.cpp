#include "souvenir.h"
#include <vector>
#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
using namespace std;

long long buy_souvenir(std::vector<int> A, std::vector<int> X, std::vector<int> B, std::vector<int> Y) {
  int n = A.size(), m = B.size();
  ll a[n + 1], x[n + 1], b[m + 1], y[m + 1], pref[max(n, m) + 1];
  for(int i = 1; i <= n; ++i)
    a[i] = A[i - 1], x[i] = X[i - 1];
  for(int i = 1; i <= m; ++i)
    b[i] = B[i - 1], y[i] = Y[i - 1];
  memset(pref, 0, sizeof(pref));
  for(int i = 1; i <= m; ++i)
    pref[i] = y[i] + pref[i - 1];
  // memo occurrences
  int occurence[n + m + 5];
  memset(occurence, -1, sizeof(occurence));
  for(int i = 1; i <= m; ++i) {
    occurence[b[i]] = i;
  }
  ll res = pref[m];
  for(int i = 1; i <= n; ++i) {
    multiset<ll> sums;
    multiset<int> index;
    ll cur_sum = 0;
    sums.insert(pref[m]);
    index.insert(0), index.insert(m + 1);
    for(int j = i; j <= n; ++j) {
      // do from subarray i to j
      cur_sum += x[j];
      if(occurence[a[j]] != -1) {
        // split at occurence
        int cur = occurence[a[j]], larger = *index.upper_bound(cur), smaller = *--index.lower_bound(cur);
        if(larger - 1 >= smaller)
          sums.erase(pref[larger - 1] - pref[smaller]);
        if(cur - 1 >= smaller)
          sums.insert(pref[cur - 1] - pref[smaller]);
        if(larger - 1 >= cur)
          sums.insert(pref[larger - 1] - pref[cur]);
        index.insert(cur);
      }
      //if(sums.size() == 0)
      //  sums.insert(0);
      //cout << i << " " << j << " " << cur_sum << " " << *--sums.end() << endl;
      res = max(res, cur_sum + *--sums.end());
    }
  }
  ll N = A.size();
  ll M = B.size();
  // sampe subtask 3 -> consider tiap subarray L, R dan consider di toko satunya maxnya berapa, increment R dengan 1 dan split array di range sebelumnya
  // pake prefsum bisa membantu
  memset(pref, 0, sizeof(pref));
  pref[0] = X[0];
  for(ll i = 1; i < N; ++i)
    pref[i] = pref[i - 1] + X[i];
  function<ll(ll, ll)> query = [&] (ll l, ll r) -> ll {
    if(l > r)
      return 0;
    return l == 0 ? pref[r] : pref[r] - pref[l - 1];
  };
  ll index[N + M + 5];
  memset(index, -1, sizeof(index));
  for(ll i = 0; i < N; ++i)
    index[A[i]] = i;
  res = max(res, query(0, N - 1));
  for(ll i = 0; i < M; ++i) {
    // i indicates start point only
    ll cur_sum = 0;
    multiset<ll> sums;
    multiset<ll> indices;
    sums.insert(query(0, N - 1)), sums.insert(0);
    indices.insert(-1), indices.insert(N);
    for(ll j = i; j < M; ++j) {
      // di array B, kita pilih dari i sampai j
      // add j as split kalo exist di array a
      cur_sum += Y[j];
      //cout << B[j] << " " << index[B[j]] << endl;
      if(index[B[j]] != -1) {
        // cari larger dan smaller
        ll larger = *indices.lower_bound(index[B[j]]), smaller = *--indices.lower_bound(index[B[j]]);
        // remove range yang dari larger ke smaller
        //cout << query(smaller + 1, larger - 1) << " " << query(smaller + 1, index[B[j]] - 1) << " " << query(index[B[j]] + 1, larger - 1) << endl;
        //cout << smaller << " " << B[j] << " " << index[B[j]] << " " << larger << endl;
        if(smaller + 1 <= larger - 1)
          sums.erase(query(smaller + 1, larger - 1));
        if(smaller + 1 <= index[B[j]] - 1)
          sums.insert(query(smaller + 1, index[B[j]] - 1));
        if(index[B[j]] + 1 <= larger - 1)
          sums.insert(query(index[B[j]] + 1, larger - 1));
        indices.insert(index[B[j]]);
      }
      sums.insert(0);
      //cout << i << " " << j << " " << cur_sum << " " << *--sums.end() << endl; 
      res = max(res, cur_sum + *--sums.end());
    }
  }
  // instead of splitting try merging
  // merge segments
  return res;
}