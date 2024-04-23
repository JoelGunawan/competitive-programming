#include <bits/stdc++.h>
using namespace std;
// int -> tipe data kembalian
// f -> nama fungsi
// x -> parameter
int f(int x, int y, int z, string s) {
  // x * x
  // 1, 2, 3, 3
  // s.size() -> 3
  return x * y * z * s.size();
}
void print(string s) {
  cout << s << endl;
}
void print(int x) {
  cout << x << endl;
}
int g(int x) {
  print(x);
  // berhenti kapan?
  // x = 0 -> berhenti (namanya base case)
  // setiap rekursi (yang ga error) PASTI punya base case
  if(x == 0)
    return 0;
  return x + g(x - 1);
}
int main() {
  cout << f(1, 2, 3, "bcd") << endl;
  print("101C");
  cout << g(5) << endl;
  /*
  string s;
  cin >> s;
  s += "def"; // menggabungkan 2 string
  // s.size(); -> banyak karakter di dalam string
  cout << s << endl;
  for(int i = 0; i < s.size(); ++i) {
    cout << "indeks ke-" << i << " memiliki nilai " << s[i] << endl;
  }
  // (int)'a' -> ubah jadi tipe data integer
  cout << (char)('a' + 10) << endl;
  */
}