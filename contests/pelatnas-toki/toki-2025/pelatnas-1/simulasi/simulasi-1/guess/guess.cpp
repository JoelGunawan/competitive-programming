#include "guess.h"

int NA, NB, NC;

void initialize(int NA, int NB, int NC) {
  ::NA = NA, ::NB = NB, ::NC = NC;
}

int guess(int K) {
  int q = ask(0, 1, 2);
  if (q == 0) {
    return 0;
  } else if (q == 1) {
    return NA + 1;
  } else if (q == 2) {
    return NA + NB + 2;
  }
}
