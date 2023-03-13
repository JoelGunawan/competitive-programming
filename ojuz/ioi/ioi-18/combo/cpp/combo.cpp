#include "combo.h"
#include <bits/stdc++.h>
using namespace std;

std::string guess_sequence(int N) {
  // determine first instance -> 2 operations
  // the rest should be able to be done constructively
  // AB
  // AC
  // BA
  // BC
  // CA
  // CB
  // AA
  // BB
  // CC
  // try to find combo that can find the result in 2 moves !!!
  // AB, AA, BC
  // 3 -> ABA, ABB, ABC, know 2 chars are AB, reset ASAP
  // 2 -> AA, AC -> can add 1 op to know first and second char
  // 1 -> BA, BB, BC -> know what first char is B, can just reset ASAP
  // 0 -> CC, CA, CB -> we know next char, can just reset ASAP
  // next: try to search 3 of those at once while determining next element
  // mis AA AC
  // -> just use 1 more to find
  // -> ABA ABB ABC
  // just brute force bagi kasus aja ga sih :D
  // DABA DABB DABC DB -> init query
  // D -> cur prefix
  // determine init
  vector<char> A;
  int X = press("AB");
  string cur = "";
  if(X == 2)
    cur = "AB", A = {'B', 'X', 'Y'};
  else {
    if(X == 1) {
      X = press("A");
      if(X) {
        cur += 'A', A = {'B', 'X', 'Y'};
      }
      else
        cur += 'B', A = {'A', 'X', 'Y'};
    }
    else {
      X = press("X");
      if(X)
        cur += 'X', A = {'A', 'B', 'Y'};
      else
        cur += 'Y', A = {'A', 'B', 'X'};
    }
  }
  while(cur.size() < N) {
    /*
    if(N - cur.size() >= 3) {
      int X = press(cur + A[0] + A[0] + A[0] + cur + A[0] + A[0] + A[1] + cur + A[0] + A[0] + A[2] + cur + A[1]);
      if(X == 3) {
        cur += A[0] + A[0];
        continue;
      }
      else if(X == 2) {
        // antara A[0] + A[1] atau A[0] + A[2]
        X = press(cur + A[1]);
        if(X == 2)
          cur += A[1];
        else
          cur += A[2];
      }
      else if(X == 1) {
        cur += A[1];
      }
      else
        cur += A[0];
    }
    */
    if(N - cur.size() >= 2) {
      X = press(cur + A[0] + A[0] + cur + A[0] + A[1] + cur + A[0] + A[2] + cur + A[1]);
      if(X == cur.size() + 2)
        cur += A[0];
      else if(X == cur.size() + 1)
        cur += A[1];
      else
        cur += A[2];
    }
    else {
      // use 2 queries to know
      X = press(cur + A[0]);
      if(X == cur.size() + 1)
        cur += A[0];
      else {
        X = press(cur + A[1]);
        if(X == cur.size() + 1)
          cur += A[1];
        else
          cur += A[2];
      }
    }
  }
  return cur;
}
