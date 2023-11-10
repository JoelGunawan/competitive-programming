#include "box.h"
#include <bits/stdc++.h>
using namespace std;
std::pair<int, int> find_box(int H, int W) {
  // H -> top to bottom
  // W -> left to right
  // binser the search space
  // cari right side of H ada ngga?
  // ada -> berarti binser lg di right side of h
  // tidak ada -> berarti binser di left side aja
  // intinya -> find latest l supaya dia ter disrupt
  // query turun doang dulu
  string query = "";
  for(int i = 0; i < H; ++i)
    query += 'v';
  pair<int, int> base = move_robot(query);
  if(base.first != H - 1)
    return make_pair(base.first + 1, base.second);
  int l = 0, r = H - 1, ans = 0;
  while(l <= r) {
    int mid = (l + r) / 2;
    if(mid == 0) {
      // coba manual aja both
      query = "";
      for(int i = 0; i < W; ++i)
        query += '>';
      base = move_robot(query);
      if(base.second != W - 1)
        return make_pair(base.first, base.second + 1);
      query = "v";
      for(int i = 0; i < W; ++i)
        query += '>';
      base = move_robot(query);
      if(base.second != W - 1)
        return make_pair(base.first, base.second + 1);
    }
    //cout << mid << endl;
    // cek di baris mid ada atau tidak, kalo ada lgsg stop
    query = "";
    for(int i = 0; i < mid; ++i)
      query += 'v';
    for(int i = 0; i < W; ++i) 
      query += '>';
    base = move_robot(query);
    if(base.second != W - 1)
      return make_pair(base.first, base.second + 1);
    // kalo ga berarti aman, lanjut 
    query = "";
    int d = 0;
    for(int i = 0; i < mid; ++i) {
      query += 'v';
      ++d;
    }
    for(int j = mid; j < H - 1; ++j) {
      for(int i = 0; i < W - 1; ++i) {
        query += ">v^";
      }
      for(int i = 0; i < W - 1; ++i)
        query += '<';
      if(j != H - 2)
        query += 'v', ++d;
    }
    base = move_robot(query);
    //cout << "DEB " << d << " " << l << " " << r << " " << base.first << endl;
    if(base.first != d) {
      l = mid + 1, ans = mid;
    }
    else
      r = mid - 1;
  }
  // ada ans
  //assert(ans != -1);
  query = "";
  for(int i = 0; i < ans; ++i)
    query += 'v';
  for(int i = 0; i < W - 1; ++i)
    query += '>';
  base = move_robot(query);
  return make_pair(base.first, base.second + 1);
  // cek di l 
}
