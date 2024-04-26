#include <bits/stdc++.h>
using namespace std;
int main() {
  // perulangan (for loop)
  // 1 + 2 + 3 + ... + n
  int n;
  cin >> n;
  int jumlah = 0;
  // for loop berjalan n kali
  // misal, n aku tambah sebanyak 5
  // maka waktu jalan kode akan bertambah sebanyak 5 operasi
  // n tambah 100
  // jumlah operasi/waktu jalannya akan bertambah sebanyak 100 operasi
  // Kompleksitas Waktu: O(N)
  // n = 100 -> for loop jalan 100x
  // n = 2000 -> for loop jalan 2000x
  for(int i = 1; i <= n; i++) { 
    jumlah += i; // kode ini jalan berapa kali? -> n kali
  }
  cout << jumlah << endl;
  // for(deklarasi variabel; kondisi; perubahan variabel)
  // i++ (sama dengan i = i + 1)
  // ++i (sama dengan i = i + 1)
  // i-- (sama dengan i = i - 1)
  // --i (sama dengan i = i - 1)
  // i = i + 1
  // i += 1
  // i += 3 (sama dengan i = i + 3)
  // i *= 2;
  // i -= 3;
  // i /= 4;
  // int x = 5;
  // // kalau yg dari luar dipakai di dalam bisa
  // // kalau yg di dalam, tidak bisa dipakai di luar
  // for(int i = 1; i < 10; i *= 2) {
  //   cout << i << " ";
  //   cout << x << endl;
  // };
  // cout << endl;
  
}