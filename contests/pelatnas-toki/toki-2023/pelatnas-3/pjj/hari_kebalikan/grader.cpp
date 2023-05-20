#include "hari_kebalikan.h"
#include <iostream>

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, Q;
  cin >> N >> Q;

  vector<int> L, R, k, x;
  L.resize(Q);
  R.resize(Q);
  k.resize(Q);
  x.resize(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> L[i] >> R[i] >> k[i] >> x[i];
  }

  vector<int> A = findA(N, Q, L, R, k, x);

  if ((int)A.size() != N) {
    cout << "-1\n";
    return 0;
  }

  for (int i = 0; i < N; ++i) {
    if (i != 0)
      cout << " ";
    cout << A[i];
  }
  cout << "\n";
  return 0;
}
