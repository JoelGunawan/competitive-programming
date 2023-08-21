#include "guess.h"
#include <bits/stdc++.h>
using namespace std;
void guess(int n) {
  // dua paling kecil dan dua paling besar selalu ga bisa dicari valuenya
  // coba (1, 2, i)
  // kalo beda" tp ada yg sama? antara i atau salah satu dr (1, 2)
  // ex 1 < 2
  // duplicate values -> salah satu dr 1/2
  // non duplicate values -> value dr i
  // bs jadi gada duplicate value?
  // kalo misal min/second min/max/second max -> no dupe
  // beda semua -> 1, i adalah maksimum/minimum/maksimum kedua/minimum kedua
  // kalo sama terus -> 1, 2 min/max
  int invalid[4];
  int a[n + 1];
  memset(a, -1, sizeof(a));
  // 
}
