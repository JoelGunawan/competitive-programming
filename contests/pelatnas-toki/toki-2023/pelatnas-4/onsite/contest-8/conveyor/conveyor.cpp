#include "conveyor.h"

#include <vector>

void Solve(int N, std::vector<int> A, std::vector<int> B) {
  std::vector<int> x(N - 1, 0), y(N, 0), z, a(N - 1, 0);
  x[0] = 1;
  y[1] = 1;
  z = Query(x, y);
  a[0] = 1;
  Answer(a);
}
