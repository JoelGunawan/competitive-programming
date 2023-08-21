#include "fish.h"
#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;

long long max_weights(int N, int M, std::vector<int> X, std::vector<int> Y,
                      std::vector<int> W) {
  // sub 1 -> return sum of W
  // sub 2 -> either take all x = 0 or x = 1
  // sub 3: y[i] = 0 -> choose either now or previous (like dp ish)
  // sub 4: y[i] <= 8 -> do dp[n][8] with O(8*8) transition
  vector<pair<int, int>> fish[N];
  for(int i = 0; i < M; ++i) {
    fish[X[i]].push_back(mp(Y[i], W[i]));
  }
  for(int i = 0; i < N; ++i)
    sort(fish[i].begin(), fish[i].end());
  vector<int> pref[N];
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < fish[i].size(); ++i) {
      if(pref[i].size())
        pref[i].pb(pref[i].back() + fish[i][j].se);
      else
        pref[i].pb(fish[i][j].se);
    }
  }
  vector<long long> dp[N];
  for(int i = 0; i < N; ++i)
    // kiri dan kanan digabung jadi all possible heights
    for(int j = 0; j < )
    dp[i].resize(pref[i].size());
  for(int i = 0; i < N; ++i) {
    if(i == 0) {

    }
    else if(i == 1)
  }
  return 0;
}
