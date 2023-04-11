#include "sel_darah_putih.h"
#include <iostream>

int main() {
  int N;
  cin >> N;

  vector<int> u(N - 1), v(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    cin >> u[i];
  }
  for (int i = 0; i < N - 1; ++i) {
    cin >> v[i];
  }

  int K;
  cin >> K;

  vector<int> c(N);
  for (int i = 0; i < N; ++i) {
    cin >> c[i];
  }

  init(N, u, v, K, c);

  int Q;
  cin >> Q;

  for (int i = 0; i < Q; ++i) {
    int op, u, k;
    cin >> op;

    if (op == 1) {
      cin >> u >> k;
      reassign(u, k);

    } else {
      cin >> u;
      cout << reinforce(u) << endl;
    }
  }

  return 0;
}