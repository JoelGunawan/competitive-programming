#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  // apakah a > b?
  // jika a > b output "true"
  // jika a = b output "sama"
  // jika tidak output "false"
  // if(kondisi (boolean)) {
    // jalankan kode di sini
  //}
  // > lebih dari
  // < kurang dari
  // >= lebih dari sama dengan
  // <= kurang dari sama dengan
  // == sama dengan
  if(a > b) {
    cout << "true" << endl;
  }
  // kalo ga masuk ke true, masuk ke else
  else if (a == b) {
    cout << "sama" << endl;  
  }
  else {
    cout << "false" << endl;
  }
}