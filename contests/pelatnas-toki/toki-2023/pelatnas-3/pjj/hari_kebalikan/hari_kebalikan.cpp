#include <bits/stdc++.h>
using namespace std;
using namespace std;
struct query {
  int l, r, k, x;
  bool operator<(const query& a) const {
    return r > a.r;
  }
};
const int lim = 5005;
struct prefix {
  int a[lim];
  prefix() {
    memset(a, 0, sizeof(a));
  }
  int query(int l, int r) {
    if(l == 0)
      return a[r];
    else
      return a[r] - a[l - 1];
  }
};
vector<int> findA(int N, int Q, vector<int> L, vector<int> R, vector<int> k,
                  vector<int> x) {
  vector<int> ret(N, -1);
  bool forced[N];
  memset(forced, 0, sizeof(forced));
  for(int i = 0; i < Q; ++i) {
    if(x[i] == 1 && k[i] == 1) {
      for(int j = L[i]; j <= R[i]; ++j)
        ret[j] = 1, forced[j] = 1;
    }
    else if(x[i] == 0 && k[i] == R[i] - L[i] + 1) {
      for(int j = L[i]; j <= R[i]; ++j)
        ret[j] = 0, forced[j] = 1;
    }
  }
  // kasus lain: pilih salah satu sebagai 0/1 dari seluruh array
  // pilih yg required kemunculannya paling awal
  // kalau misal ada double counting bermasalah coba 
  vector<pair<int, int>> zero, one;
  for(int i = 0; i < Q; ++i) {
    if(x[i] == 1 && k[i] == R[i] - L[i] + 1) {
      // there is at least one occurence of '1' in this range
      bool f = 0;
      int x = 0;
      for(int j = L[i]; j <= R[i]; ++j) {
        if(ret[j] == 1) {
          f = 1;
          break;
        }
      }
      if(!f)
        one.push_back({L[i], R[i]});
    }
    else if(x[i] == 0 && k[i] == 1) {
      // there is at least one occurence of '0' in this range
      bool f = 0;
      for(int j = L[i]; j <= R[i]; ++j) {
        if(ret[j] == 0) {
          f = 1;
          break;
        }
      }
      if(!f)
        zero.push_back({L[i], R[i]});
    }
  }
  sort(zero.begin(), zero.end());
  sort(one.begin(), one.end());
  for(int i = 0; i < 10; ++i) {
    // nanti kita iterate tiap zero
    // kita ganti jadi 0 semua, kecuali dia udah fulfilled
    for(int j = 0; j < N; ++j) {
      for()
    }
  }
  // tiap query coba ganti ith element in its range gtu jadi 0/1 accordingly?
  // nanti tiap query dia bakal construct prefix sum
  // jadi nanti O(NQ)
  return ret;
}