#include "mark.h"
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
// returns vector of two pairs that represent number n
vector<vector<pair<int, int>>> mark_card(int n) {
  vector<vector<pair<int, int>>> a;
  // generate a code for the card
  // set of coretan
  // coba coretan non putar
  // 16 poin
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j <= 2; ++j) {
      // horizontal dan vertikal
      if(i == 1 && j == 1)
        continue;
      if(mp(j, i + 1) != mp(1, 1))
        a.pb({mp(j, i), mp(j, i + 1)});
      if(mp(i + 1, j) != mp(1, 1))
        a.pb({mp(i, j), mp(i + 1, j)});
    }
  }
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < 2; ++j) {
      // diagonal 1x1
      a.pb({mp(i, j), mp(i + 1, j + 1)});
      a.pb({mp(i + 1, j), mp(i, j + 1)});
    }
  }
  for(int i = 0; i < 2; ++i) {
    // diagonal 1x2
    a.pb({mp(i, 0), mp(i + 1, 2)});
    a.pb({mp(i + 1, 0), mp(i, 2)});
  }
  for(int i = 0; i < 2; ++i) {
    // diagonal 2x1
    a.pb({mp(0, i), mp(2, i + 1)});
    a.pb({mp(0, i + 1), mp(2, i)});
  }
  vector<vector<pair<int, int>>> ret;
  if(n < (1 << 24)) {
    ret.pb({mp(1, 1), mp(1, 2)});
    for(int i = 23; i >= 0; --i) {
      if((1 << i) & n) {
        ret.pb(a[i]);
      }
    }
  }
  else if(n < (1 << 25)) {
    n -= 1 << 24;
    ret.pb({mp(0, 1), mp(1, 1)});
    ret.pb({mp(1, 1), mp(1, 2)});
    for(int i = 23; i >= 0; --i) {
      if((1 << i) & n) {
        ret.pb(a[i]);
      }
    }
  }
  else {
    n -= 1 << 25;
    ret.pb({mp(0, 1), mp(1, 1)});
    ret.pb({mp(1, 1), mp(1, 2)});
    ret.pb({mp(1, 1), mp(2, 1)});
    for(int i = 23; i >= 0; --i) {
      if((1 << i) & n) {
        ret.pb(a[i]);
      }
    }
  }
  
  // pakai node yg di tengah grid as reference aja
  // sisanya ngikutin
  // nanti buat fungsi rotate
  // kalo ada yg di tengah -> mark pake yg di tengah
  // kalo cmn di pinggir aja -> mark 
  return ret;
}