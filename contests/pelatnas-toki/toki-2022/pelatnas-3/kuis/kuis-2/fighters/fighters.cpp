#include "fighters.h"

#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long minimum_strength(std::vector<int> A, std::vector<int> B) {
  int N = A.size();
  int M = B.size();
  int op_cnt = (N - 1) / (M - 1);
  multiset<pair<ll, int>> a;
  for(int i = 0; i < N; ++i)
    a.insert({A[i], i});
  vector<pair<int, int>> b(M);
  for(int i = 0; i < M; ++i)
    b[i] = {B[i], i};
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  for(int i = 0; i < op_cnt; ++i) {
    auto it = a.begin();
    vector<ll> tmp(M);
    ll maxi = 0;
    for(int j = 0; j < M; ++j) {
      tmp[j] = (*it).first + b[j].first;
      maxi = max(tmp[j], maxi);
      ++it;
    }
    vector<pair<ll, int>> tmp2(M);
    for(int j = 0; j < M; ++j) {
      tmp2[j] = {(*--a.upper_bound({maxi - b[j].first, 1e9})).first + b[j].first, -(*--a.upper_bound({maxi - b[j].first, 1e9})).second};
      a.erase(--a.upper_bound({maxi - b[j].first, 1e9}));
    }
    vector<int> call(M);
    for(int j = 0; j < M; ++j) {
      call[b[j].second] = -tmp2[j].second;
    }
    fight(call);
    sort(tmp2.begin(), tmp2.end());
    a.insert({tmp2.back().first, -tmp2.back().second});
  }
  return (*a.begin()).first;
}
