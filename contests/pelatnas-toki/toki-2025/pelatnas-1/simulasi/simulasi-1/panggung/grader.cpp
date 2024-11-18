#include "panggung.h"

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  std::cin >> N >> M;
  int Q;
  std::cin >> Q;
  std::vector<int> X1(Q), Y1(Q), X2(Q), Y2(Q);
  for(int i = 0; i < Q; i++)
    cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
  int length = panggung(N, M, Q, X1, Y1, X2, Y2);
  std::cout << length << std::endl;
  return 0;
}