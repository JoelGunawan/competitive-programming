#include "guess.h"
#include <bits/stdc++.h>
using namespace std;
int NA, NB, NC;

void initialize(int NA, int NB, int NC) {
  ::NA = NA, ::NB = NB, ::NC = NC;
}

int guess(int K) {
  // ask returns an integer 0-2
  // in first 4 subtasks return 0-1
  // binser K berdasarkan la, ra, lb, rb
  // bisa pindah search spacenya
  // yang minimum yang bakalan dikurangin search spacenya
  int res = 0;
  int la = 0, lb = 0, lc = 0;
  ++K;
  if(K >= (NA + NB) / 2) {
    K = NA + NB - K;
    // cari dari belakang
    // agak susah :(
    int la = NA - 1, lb = NB - 1;
    while(K > 1) {
      int mida = la - K / 2 + 1, midb = lb - K / 2 + 1;
      int query = ask(max(mida, 0), max(midb, 0), 0);
      if(query == 0)
        lb = midb + 1;
      else
        la = mida + 1;
      K -= K / 2;
    }
    if(ask(min(la, NA), min(lb, NB), 0) == 0)
      return NA + lb;
    else
      return la;
    return 0;
  }
  int query;
  while(K > 1) {
    // compare try to compare bottom and top
    // either way the search space will be reduced by 1/2 K
    int mida = la + K / 2 - 1, midb = lb + K / 2 - 1;
    // for now just do all except last sub
    if(ask(min(mida, NA), min(midb, NB), 0) == 0)
      la = mida + 1;
    else
      lb = midb + 1;
    K -= K / 2;
  }
  // compare between la and lb
  if(lb >= NB || (la <= NA && ask(min(la, NA), min(lb, NB), 0) == 0))
    return la;
  else
    return NA + lb;
  /*
  while(K > 2) {
    // compare try to compare bottom and top
    // either way the search space will be reduced by 1/2 K
    int mida = la + K / 3 - 1, midb = lb + K / 3 - 1, midc = lc + K / 3 - 1;
    // for now just do all except last sub
    query = ask(min(mida, NA), min(midb, NB), min(midc, NC));
    if(query == 0)
      la = mida + 1;
    else if(query == 1)
      lb = midb + 1;
    else
      lc = midc + 1;
    K -= K / 3;
  }
  // compare between la and lb
  query = ask(min(la, NA), min(lb, NB), min(lc, NC));
  if(K != 1) {
    if(query == 0)
      ++la;
    else if(query == 1)
      ++lb;
    else
      ++lc;
    query = ask(min(la, NA), min(lb, NB), min(lc, NC));
  }
  if(query == 0)
    return la;
  else if(query == 1)
    return NA + lb;
  else
    return NA + NB + lc;
  */
}