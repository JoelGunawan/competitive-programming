#include "box.h"

#include <cassert>
#include <cstdio>
#include <string>
#include <utility>

int moveCounter;
int H, W;
int secretBoxX, secretBoxY;

void wa() {
  printf("WA\n");
  exit(0);
}

std::pair<int, int> move_robot(std::string s) {
  if (s.size() > 20000) wa(); 
  ++moveCounter;
  if (moveCounter > 2500) wa();

  int x = 0, y = 0;
  for (char c : s) {
    int nx = x, ny = y;
    if (c == '<') --ny;
    else if (c == '>') ++ny;
    else if (c == '^') --nx;
    else if (c == 'v') ++nx;

    if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
    if (nx == secretBoxX && ny == secretBoxY) continue;

    x = nx; y = ny;
  }
  return std::make_pair(x, y);
}

int main() {
  assert(2 == scanf("%d %d", &H, &W));
  assert(2 == scanf("%d %d", &secretBoxX, &secretBoxY));

  moveCounter = 0;
  std::pair<int, int> ans = find_box(H, W);

  printf("%d\n", moveCounter);
  printf("%d %d\n", ans.first, ans.second);
  return 0;
}
