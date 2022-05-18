#include "game.h"

#include <vector>
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> ans;
map<int, bool> vis;
map<int, int> res;
int cnt = 0;
int query(int number) {
  if(!vis[number])
    vis[number] = 1, res[number] = ask_minimum_xor(number), ++cnt;
  return res[number];
}
void dnc(int cur, int depth, int prev = -1, int prev_state = -1) {
  //cout << cur << " " << depth << endl;
  // cur -> current mask
  // depth -> which bit are we on
  // check on bit
  // tiap query kita pasti tahu suatu nilai baru
  // kita tahu minimumnya berapa, jadi g mgkn lebih kecil dari minimum
  // kalo misal jadi 0 -> lebih kecil dari minimum -> pasti tidak bisa
  // untuk query minimum -> kita query dengan semua 0
  // untuk query maksimum -> kita ganti semua jadi 1
  // jika min == max, masukkan ke ans dan return
  // jika min != max, maka rekursi min sendiri dan maks sendiri hingga min = maks
  // jika kita sudah tahu maks dalam satu range, maka kita tinggal cari berdasarkan bit pertama yang beda
  // kalo semua yang bit pertama beda == maks, ikut ke rekursinya maks
  // semua yang bit pertama beda == 0, ikut rekursinya ke min
  // find first different bit
  // cur itu yang sudah di fix kan
  if(depth < 0) {
    ans.pb(cur);
    return;
  }
  int tmp = 0;
  for(int i = depth; i >= 0; --i) {
    tmp += 1 << i;
  }
  // prev itu min
  int minimum, maximum;
  if(prev_state == 0) {
    minimum = prev, maximum = query(cur + tmp);
    for(int i = depth; i >= 0; --i) {
      if((1 << i) & maximum)
        maximum -= (1 << i);
      else
        maximum += (1 << i);
    }
  }
  // prev itu max
  else if(prev_state == 1) {
    maximum = prev, minimum = query(cur);
  }
  else {
    minimum = query(cur), maximum = query(cur + tmp);
    for(int i = depth; i >= 0; --i) {
      if((1 << i) & maximum)
        maximum -= (1 << i);
      else
        maximum += (1 << i);
    }
  }
  //cout << cur << " " << minimum + cur << " " << maximum + cur << endl;
  if(minimum == maximum) {
    ans.pb(minimum + cur);
  }
  else {
    int diff;
    tmp = 0;
    for(int i = depth; i >= 0; --i) {
      if((1 << i) & maximum && !((1 << i) & minimum)) {
        diff = i;
        break;
      }
      else if((1 << i) & maximum)
        tmp += 1 << i;
    }
    // maximum -> cari maks dari mask mask diff ke belakang
    // minimum -> cari min dari mask diff ke belakang
    int maxi = 0, mini = 0;
    for(int i = diff - 1; i >= 0; --i) {
      if((1 << i) & minimum)
        mini += 1 << i;
      if((1 << i) & maximum)
        maxi += 1 << i;
    }
    dnc(tmp + cur + (1 << diff), diff - 1, maxi, 1);
    dnc(tmp + cur, diff - 1, mini, 0);
  }
}
std::vector<int> play_game(int N) {
  // kita mulai dari bit paling atas, kita buat semacam pola yang kita ikutin mirip trie
  // untuk tiap depth, kita coba bit on dan bit off
  // jika di cur PASTI ada, maka:
  // jika bit on tidak ada, maka ke bit off saja (pasti ada, langsung ke depth bawahnya)
  // jika bit on ada, maka bisa jadi ada bit off (kita cek bit off apakah ada atau tidak)
  // jika tidak ada bit off maka cut off saja, jika ada, lanjut rekursi
  dnc(0, 29);
  //cout << cnt << endl;
  //cout << "TEST" << endl;
  return ans;
}
