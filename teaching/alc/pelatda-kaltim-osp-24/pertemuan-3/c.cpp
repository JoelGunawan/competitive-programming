#include <bits/stdc++.h>
using namespace std;
// operator logika
int main() {
  int a, b;
  cin >> a >> b;
  // jika a dan b lebih dari 10, maka output yes
  // operator logika/kondisi
  // operator and/dan
  // kondisi1 && kondisi2 -> dua"nya harus true agar hasilnya true
  if(a > 10 && b > 10) {
    cout << "ya" << endl;
  } 
  // operator or/atau
  // kondisi || kondisi2 -> setidaknya salah satu harus true agar hasilnya true
  if(a > 10 || b > 10) {
    cout << "salah satu" << endl;
  }
  // operator xor
  // kondisi1 ^ kondisi2 -> TEPAT salah satu harus true agar hasilnya true
  if((a > 10) ^ (b > 10)) {
    cout << "tepat salah satu" << endl;
  }
}