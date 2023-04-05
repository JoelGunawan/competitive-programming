#include "sel_darah_merah.h"
#include <iostream>

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  vector<int> L, R;

  cin >> N;
  L.resize(N);
  R.resize(N);

  for (int i = 0; i < N; ++i) {
    cin >> L[i];
  }

  for (int i = 0; i < N; ++i) {
    cin >> R[i];
  }

  initialize(N, L, R);

  int Q;
  cin >> Q;

  for (int i = 0; i < Q; ++i) {
    int M;
    vector<int> S;

    cin >> M;
    S.resize(M);

    for (int j = 0; j < M; ++j) {
      cin >> S[j];
    }

    if (configurationExists(M, S)) {
      cout << "CONFIGURATION EXISTS\n";
    } else {
      cout << "CONFIGURATION DOESN'T EXIST\n";
    }
  }
}