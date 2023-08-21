#include "anna.h"
#include <bits/stdc++.h>
using namespace std;

void Anna( int N, long long X, int K, int P[] ){
  bool inval[N + 1];
  // 110 valid positions
  // mau simpan 2^60
  memset(inval, 0, sizeof(inval));
  for(int i = 0; i < K; ++i)
    inval[P[i]] = 1;
  int idx = 0;
  // simpan 2 jadi 1
  // kalo ada space size 3, jadiin buat simpan 2 element
  // 110
  // 101
  // 100
  // 111
  // tiap index simpan a set of positions sedemikian rupa sehingga bisa represent tiap angka?

  for(int i = 0; i < 60; ++i) {
    if(idx >= N)
      return;
    while(inval[idx] || inval[idx + 1]) {
      Set(idx, 0), ++idx;
      if(idx == N)
        return;
    } 
    Set(idx, 1);
    if(idx == N - 1)
      return;
    //cout << idx + 1 << " " << (int)(bool)((1ll << i) & X) << endl;
    Set(idx + 1, (int)(bool)((1ll << i) & X));
    //cout << (int)(bool)((1 << i) & X) << endl;
    //cout << i << " " << idx << endl;
    idx += 2;
  }
  while(idx < N)
    Set(idx++, 0);
  //cout << idx << endl;
  //cout << "ANNA ONCE" << endl;
}
