#include "maze.h"

#include <cassert>
#include <cstdio>

#include <vector>

int main() {
  int R, C, N, Sr, Sc, Gr, Gc;
  assert(3 == scanf("%d %d %d", &R, &C, &N));
  assert(2 == scanf("%d %d", &Sr, &Sc));
  assert(2 == scanf("%d %d", &Gr, &Gc));
  std::vector<std::vector<char>> A(R, std::vector<char>(C));
  for (int i = 0; i < R; ++i) {
    getchar();  // Read endline
    for (int j = 0; j < C; ++j) {
      scanf("%c", &A[i][j]);
    }
  }

  printf("%d\n", minimum_stamps(R, C, N, Sr, Sc, Gr, Gc, A));
}
