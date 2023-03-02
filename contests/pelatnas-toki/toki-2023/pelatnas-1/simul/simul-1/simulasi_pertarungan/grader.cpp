#include "simulasi_pertarungan.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

namespace {
void wrong_answer(string msg = "") {
  cout << "Wrong Answer: " << msg << endl;
  exit(0);
}

int M, K, L, minSimulations;

int cnt_query = 0;
int cnt_false_answer = 0;
} // namespace

bool fight(int P) {
  if (P < 0 || P > M) {
    wrong_answer("P tidak berada di dalam rentang [0, M]!");
  }

  if(cnt_false_answer == K){
    wrong_answer("Loid sudah tidak memiliki nyawa, simulasi tidak boleh lagi dilakukan.");
  }

  cnt_query++;
  if (cnt_query > min(M, minSimulations)) {
    wrong_answer("Pemanggilan fungsi fight sudah melewati batas pemanggilan.");
  }

  if (L > P) {
    return true;
  } else {
    cnt_false_answer++;

    return false;
  }
}

int main() {
  bool simulate;

  cin >> M >> K >> simulate >> L;

  minSimulations = findMinSimulations(M, K);

  cout << minSimulations << " " << findL(simulate) << endl;
}
