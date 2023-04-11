#include "virus.h"
#include <iostream>

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;

  vector<int> u(N - 1), v(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    cin >> u[i];
  }
  for (int i = 0; i < N - 1; ++i) {
    cin >> v[i];
  }

  vector<int> D(M);
  for (int i = 0; i < M; ++i) {
    cin >> D[i];
  }

  vector<int> C(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> C[i];
  }

  vector<int> ans = countViruses(N, M, Q, u, v, D, C);

  if ((int)ans.size() == Q) {
    for (int i = 0; i < Q; ++i) {
      cout << ans[i] << endl;
    }
  }

  return 0;
}
