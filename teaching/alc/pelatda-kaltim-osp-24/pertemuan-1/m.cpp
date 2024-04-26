#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  // kode 1
  for(int i = 1; i <= n; ++i) { // n kali
    for(int j = m; j >= 1; --j) { // m kali
      cout << "*" << endl; // n * m kali
    }
  }
  // ada hal yang terjadi m kali, hal ini terjadi n kali
  // kompleksitas waktu: O(m*n)

  // kode 2
  // kompleksitas waktu: O(m - n)
  for(int i = n; i <= m; ++i) { // m - n kali
    cout << "*" << endl; // m - n kali
  }

  // kode 3
  // kompleksitas waktu: O(n + m)
  for(int i = 1; i <= n; ++i) { // n kali
    cout << "*";
  }
  for(int i = 1; i <= m; ++i) { // m kali
    cout << "*";
  }

  // kode 1
  for(int i = 1; i <= n; ++i) { // n kali
    for(int j = m; j >= 1; --j) { // m kali
      cout << "*" << endl;
    }
  }
  // ada hal yang terjadi m kali, hal ini terjadi n kali
  // kompleksitas waktu: O(m*n)

  // tujuan analisis kompleksitas:
  // input n
  // bisa tahu, waktu jalan kodenya itu bergantung bagaimana ke n?
  // n = 100 -> n = 1000
  // 10x lebih lambat?
  // 100x lebih lambat?
  // 1000x lebih lambat?
  // 5x lebih lambat?
  // sama saja

  // kode 4
  // 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, ..., ...
  // waktu jalan kode itu naik berdasarkan kebalikan dari pangkat
  // * 2 untuk n, waktu jalan "tambah 1"
  // * 16 untuk n, waktu jalan "tambah 3"
  // kebalikan pangkat -> logaritma
  // n = 512 -> 2^9 -> 9. log2(512) = 9 
  // n = 128 -> 2^7 -> 7. log2(128) = 7
  // kompleksitas waktu: O(M*logN)
  for(int i = 1; i <= n; i *= 2) { // logN kali
    for(int j = 1; j <= m; ++j) { // M kali
      cout << "*";
    }
  }

  // kode 5
  // kompleksitas waktu: O(n^2*m)
  for(int i = 1; i <= n; ++i) { // n kali
    // n kali
    for(int j = 1; j <= m; ++j) { // m kali
      // n * m kali
      for(int k = 1; k <= n; ++k) { // n kali
        // n * m * n kali
        // n^2 * m
        cout << "*" << endl;
      }
    }
  }

  // kompleksitas waktu: O(n*log3(m)*sqrt(m))
  // sqrt(m) -> akar m
  for(int i = 1; i <= n; ++i) { // n kali
    for(int j = 1; j <= m; j *= 3) { // log3(m) kali
      for(int j = 1; j <= sqrt(m); ++j) { // sqrt(m) kali

      }
    }
  }
}