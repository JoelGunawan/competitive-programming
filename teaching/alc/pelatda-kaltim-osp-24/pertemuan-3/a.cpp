#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
// tdk pakai bilangan prima
bool cek_prima(int n) {
  // akar(n)
  // sqrt(angka) -> akar dari angka
  for(int i = 2; i <= sqrt(n); ++i) {
    if(n % i == 0) {
      // bukan prima
      return false;
    }
  }
  return true; // prima, karena tdk ada faktor dari 2 ... sqrt(n)
}

// pakai bilangan prima
bool cek_prima2(int n) {
  for(int i = 0; i < primes.size() && primes[i] <= sqrt(n); ++i) {
    if(n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  bool prima[n + 1];
  // untuk membuat seluruh nilai array boolean jadi true
  memset(prima, 1, sizeof(prima)); 
  // digunakan untuk jadi false 
  // memset(prima, 0, sizeof(prima));
  prima[1] = false;
  for(int i = 2; i <= n; ++i) {
    if(prima[i]) {
      for(int j = 2 * i; j <= n; j += i) {
        prima[j] = false;
      }
    }
  }
  
  for(int i = 1; i <= n; ++i) {
    if(prima[i]) {
      primes.push_back(i);
    }
  }
  cout << cek_prima(203) << endl;
  cout << cek_prima2(203) << endl;
}