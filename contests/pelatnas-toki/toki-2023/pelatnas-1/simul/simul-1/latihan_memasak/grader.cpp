#include "latihan_memasak.h"
#include <iostream>

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M, Y;
  cin >> N >> M >> Y;

  vector<int> r, h, L, R;
  r.resize(N);
  h.resize(N);
  L.resize(M);
  R.resize(M);

  for (int i = 0; i < N; ++i) {
    cin >> r[i];
  }

  for (int i = 0; i < N; ++i) {
    cin >> h[i];
  }

  for (int i = 0; i < M; ++i) {
    cin >> L[i];
  }

  for (int i = 0; i < M; ++i) {
    cin >> R[i];
  }

  vector<long long> vY = findY(N, M, Y, r, h, L, R);

  if ((int)vY.size() != Y) {
    cout << "-1\n";
    return 0;
  }

  for (int i = 0; i < Y; ++i) {
    if (i != 0)
      cout << " ";
    cout << vY[i];
  }
  cout << endl;

  return 0;
}
