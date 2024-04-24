#include <bits/stdc++.h>
using namespace std;
void tc() {
  // pikirkan operasi yg kita punya
  // + 1
  // hapus 1
  // bagi per kasus:
  // totalnya udah habis dibagi 3 -> 0 operasi
  // totalnya dibagi 3 sisa 2 -> +1 -> 1 operasi
  // totalnya dibagi 3 sisa 1
  // ada 2 kemungkinan:
  // - hapus 1 elemen yg klo dibagi 3 sisa 1
  // - +1 2 kali
  int n;
  cin >> n;
  int a[n + 5];
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int sisa = 0;
  for(int i = 1; i <= n; ++i) {
    sisa += a[i] % 3;
    sisa %= 3;
  }
  if(sisa == 0) {
    cout << 0 << endl;
  }
  else if(sisa == 2) {
    cout << 1 << endl;
  }
  else {
    // sisa == 1
    bool ada_sisa1 = false;
    for(int i = 1; i <= n; ++i) {
      // kalo ada elemen yang sisanya 1, maka kita bisa hapus
      if(a[i] % 3 == 1)
        ada_sisa1 = true;
    }
    if(ada_sisa1) 
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while(t--)
    tc();
}