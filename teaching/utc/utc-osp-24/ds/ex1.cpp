#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
  if(a.first == b.first) {
    return a.second < b.second;
  }
  else {
    return a.first < b.first;
  }
}
int main() {
  int n;
  cin >> n;
  set<pair<int, int>> s;
  // ganjil median ada di med1
  // genap, med1 dan med2
  auto med1 = s.begin(), med2 = s.begin();
  cout << fixed << setprecision(1);
  for(int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    s.insert(make_pair(x, i));
    if(i == 1) {
      med1 = s.begin();
      cout << x << endl;
    }
    // comparison of pair:
    // berdasarkan first
    // berdasarkan second
    // kasus ganjil
    else if(i & 1) {
      // first -> x
      // second -> i
      if(make_pair(x, i) < (*med1)) {
        // jadi median 1, biarin
      }
      else if(make_pair(x, i) > (*med2)) {
        // jadi median 2
        med1 = med2;
      }
      else {
        // ada di tengah"nya, di kanan med1
        ++med1;
      }
      cout << (*med1).first / 1.0 << endl;
    }
    // kasus genap
    else {
      // insert > current median -> gabungan median sekarang dan elemen yg lebih dari elemen sekarang
      // insert < current median -> gabugnan median sekarang dan elemen yg lebih kecil dari elemen sekarang
      if(make_pair(x, i) < *med1) {
        // geser ke kiri
        med2 = med1;
        --med1;
      }
      else {
        // geser ke kanan
        med2 = med1;
        ++med2;
      }
      cout << ((*med1).first + (*med2).first) / 2.0 << endl;
    }
  } 
}