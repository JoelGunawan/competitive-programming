#include <bits/stdc++.h>
using namespace std;
int jumlah;
int memo[1000];
int f(int n) {
  // jika sudah dihitung sebelumnya, memo tidak negatif 1, maka langsung kembalikan nilai memo
  if(memo[n] != -1) {
    return memo[n];
  }
  cout << "DEBUG " << n << endl;
  ++jumlah;
  // base case
  if(n == 1 || n == 2) {
    return 1;
  }
  else {
    // fibonacci ke-n itu nilainya memo[n]
    memo[n] = f(n - 1) + f(n - 2);
    return memo[n];
  }
}
int main() {
  memset(memo, -1, sizeof(memo)); // set seluruh isi memo ke -1
  int n;
  cin >> n;
  cout << f(n) << endl;
  cout << "Jumlah Pemanggilan: " << jumlah << endl;
}